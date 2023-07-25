#include "iotest.decl.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "ckio.h"

CProxy_Main mainProxy;


class Main : public CBase_Main {
	Main_SDAG_CODE;
	Ck::IO::File _file; // the file that is going to be opened
	CProxy_Reader readers; // holds the array of readers
	size_t num_reads_done = 5; // initialize the number of reads to 5 and count down
	Ck::IO::Session current_session;
	double start_time;
	double end_time;
	size_t file_size;
	size_t num_pes;
	size_t num_io_buffers = 32;
	size_t num_readers = 64;
	std::string TEST_FILE;
	std::string dump_file;
	// std::string TEST_FILE;
public:
	Main(CkArgMsg* msg){
		traceRegisterUserEvent("register memory", 10);
		if(msg -> argc < 3) {
			CkPrintf("Usage: iotest <test_file> <number of pes> <number of io buffers(optional)> <number of client readers(optional)>\n");
			CkExit();

		}
		TEST_FILE = std::string(msg -> argv[1]); // power of the file
		num_pes = atoi(msg -> argv[2]); // the number of pes
		if(msg -> argc > 3){
			num_io_buffers = atoi(msg -> argv[3]);	
		}
		if(msg -> argc > 4){
			num_readers = atoi(msg -> argv[4]);
		}	
		if(msg -> argc > 5){
			dump_file = std::string(msg -> argv[5]);
		}
		CkPrintf("Args: TEST_FILE=%s, num_pes=%zu, num_io_bufers = %zu, num_readers=%zu, dump_file=%s\n", TEST_FILE.c_str(), num_pes, num_io_buffers, num_readers, dump_file.c_str());
		std::ifstream ifs;
		ifs.open(TEST_FILE);
		ifs.seekg(0, std::ios::end);
		file_size = ifs.tellg();
		ifs.close();
		thisProxy.startReading();
	}
	// returns a buffer of a sequential read so that the parallel read at offset with number of bytes length can be verified
	char* sequentialRead(size_t offset, size_t bytes){
		char* buffer = new char[bytes];
	 	memset(buffer, 125, bytes+1);
		int pos = 0;
		std::ifstream ifs(TEST_FILE);
		ifs.seekg(offset);

		while(ifs.good() && pos < bytes){
			buffer[pos] = ifs.get();
			if((int)(buffer[pos]) == -1) { 
				CkPrintf("Why does this have a character with ASCII value of -1\n");
			}
			if(ifs.fail()) {
				CkPrintf("READ FAILED ON when reading in to buffer[%d]\n", pos);
			}
			CkEnforce((int)(buffer[pos]) != -1);
			pos++;
		}
		ifs.close();
		return buffer;
	}

	void doneReading(CkReductionMsg* msg){
		end_time = CkWallTimer();
		std::cerr << "Just finished reading\n";
		// CkCallback cb(CkIndex_Main::logging(0), mainProxy);
		traceEnd(); // end the trace
		CkPrintf("About to try verifying the full read\n");
		readers.verifyFullFileRead(TEST_FILE, file_size, num_readers); // make sure all the reads were correct
		// mainProxy.logging(0);
		
		// CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		// Ck::IO::closeReadSession(current_session, cb);
		// CkPrintf("Total time: %f\n", end_time - start_time);
	}

	void logging(CkReductionMsg* msg){
		CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		Ck::IO::closeReadSession(current_session, cb);
		CkPrintf("Total time: %f\n", end_time - start_time);
		FILE* dump_fp = fopen(dump_file.c_str(), "aw+");	
		fprintf(dump_fp, "Total time: %f\n", end_time - start_time);
		fprintf(dump_fp, "Throughput: %f\n", (file_size * 1.0) / (end_time - start_time));	
		fclose(dump_fp);
	}
};

// object that is used to enact the parallel reads
struct Reader : public CBase_Reader {
	Reader_SDAG_CODE;
	Ck::IO::ReadCompleteMsg* og_msg = 0;
	size_t _bytes;
	size_t my_offset;
	std::string testing_file;
public:
	Reader(Ck::IO::Session session, size_t file_size, size_t bytes, size_t offset, size_t num_chares){
		_bytes = file_size / num_chares;	
		my_offset = offset + thisIndex * _bytes;
		if(thisIndex == num_chares - 1) {
			_bytes = file_size - my_offset;
			CkPrintf("Reader[%d] is the last reader; has to read %zu bytes\n", thisIndex,_bytes);
		}
		#ifdef TEMP_DEBUG
			_bytes=1024 * 1024 * 4;
		#endif
		// ckout << "My offset for reader " << thisIndex << " is " << my_offset << endl;
		CkCallback test_read_cb(CkIndex_Reader::testRead(0), thisProxy[thisIndex]);	
		// CkPrintf("From Reader[%d] before issuing read: _bytes=%zu, my_offset=%zu\n", thisIndex, _bytes, my_offset); 
		//CmiPrintf("NUMBYTES: %zu", _bytes);
		Ck::IO::read(session, _bytes, my_offset, test_read_cb);
	}

	char* sequentialRead(size_t offset, size_t bytes){
		if(thisIndex == 0) CkPrintf("Reader 0 verification: starting sequential read\n");
		char* buffer = new char[bytes + 1];
		int pos = 0;
		std::ifstream ifs(testing_file);
		// CkPrintf("From Reader %d: The testing file is: %s\n", thisIndex, testing_file.c_str());
		ifs.seekg(offset);
		if(!ifs.good()){
			CkPrintf("Something is going wrong: the stream is not good\n");
		}
		while(pos < bytes && !ifs.eof()){
			buffer[pos] = ifs.get();
			if(ifs.fail()) {
				CkPrintf("READ FAILED ON when reading in to buffer[%d]\n", pos);
			}
			CkEnforce((int)(buffer[pos]) != -1);
			pos++;
		}
		buffer[bytes] = 0;
		ifs.close();
		if(thisIndex == 0) CkPrintf("Reader 0 verification: finished sequential read\n");
		return buffer;
	}

	void verify(std::string test_file){
		testing_file = test_file; // set the test file
		// CkPrintf("On Reader %d: Reader is (%zu, %zu) while ReadCompleteMsg is (%zu, %zu)\n", my_offset, _bytes, og_msg -> offset, og_msg -> bytes);
		// char* sequence = sequentialRead(og_msg -> offset, og_msg -> bytes);
		// std::string fname = "LOGGING" + std::to_string(og_msg -> offset) + "+" + std::to_string(og_msg -> bytes);
		// std::ofstream ofs(fname);	
		// ofs << "SEQUENTIAL READ RESULTS FROM READER " << thisIndex << ": ";
		// ofs.write(sequence, og_msg -> bytes);
		// ofs << "\n";
		// ofs << "PARALLEL READ RESULTS FROM READER" << thisIndex << ": ";	
		// ofs.write(og_msg -> data, og_msg -> bytes);
		// ofs << "\n";
	//	for(size_t i = 0; i< og_msg -> bytes; ++i){
	//		if(sequence[i] != og_msg -> data[i]){
	//			CkPrintf("Reader %d: At index %d, sequentialRead returned %d while parallel returned %d\n", thisIndex, i, (int)(sequence[i]), (int)(og_msg -> data[i]));
	//		}
	//		CkEnforce(sequence[i] == og_msg -> data[i]);
	//	}
		// CkEnforce(!strncmp(sequence, og_msg -> data, og_msg -> bytes));
		CkCallback cb(CkIndex_Main::logging(0), mainProxy);
		// delete[] sequence;
		delete og_msg;
		contribute(cb);
	}

	
	void verifyFullFileRead(std::string test_file, size_t file_size, size_t num_chares){
		if(!thisIndex) CkPrintf("Reader 0: starting the verification of full file read\n");
		size_t interval = file_size / num_chares;
		size_t my_offset_2 = interval * thisIndex;
		size_t num_bytes_to_read = interval;
		if(thisIndex == num_chares - 1) num_bytes_to_read = file_size - my_offset;
		if(og_msg -> bytes != num_bytes_to_read){
			CkPrintf("Reader[%d]: og_msg -> bytes=%zu, num_bytes_to_read=%zu\n", thisIndex, (og_msg -> bytes), num_bytes_to_read);
		}
		CkEnforce(og_msg -> bytes == num_bytes_to_read);
		if(og_msg -> offset != my_offset_2){
			CkPrintf("Reader[%d]: og_msg -> offset=%zu, my_offset_2=%zu\n", thisIndex, (og_msg -> offset), my_offset_2);
		}
		CkEnforce(og_msg -> offset == my_offset);
		CkEnforce(og_msg -> bytes == num_bytes_to_read);
		testing_file = test_file;
		char* sequence = sequentialRead(my_offset, num_bytes_to_read);
		if(!thisIndex) CkPrintf("Reader 0 verification: starting verification of the data\n");
	//	std::string s(og_msg -> data, num_bytes_to_read);
	//	CkPrintf("What the Reader[%d] received: %s\n", thisIndex, s.c_str());
	//	std::string t(sequence, num_bytes_to_read);
	//	CkPrintf("What the sequential received: %s\n", t.c_str());
		for(size_t i = 0; i < num_bytes_to_read; ++i){
			if(og_msg -> data[i] != sequence[i]){
				CkPrintf("Reader[%d]: og_msg -> data[%d]=%c; sequence[%d]=%c\n", thisIndex, i, (og_msg -> data[i]), i, sequence[i]);
				CkPrintf("size_t values: og->msg[%d] is %d; sequence[%d] is %d\n", i, (int)(og_msg -> data[i]), i, (int)(sequence[i]));
			}
			CkEnforce(og_msg -> data[i] == sequence[i]);
		}

		if(!thisIndex) CkPrintf("Reader 0 verification: finished verification of the data\n");
		if(!thisIndex) CkPrintf("Reader 0: finished the verification of full file read\n");
		CkCallback cb(CkIndex_Main::logging(0), mainProxy);
		// delete[] sequence;
		delete og_msg;
		contribute(cb);
	}

};

#include "iotest.def.h"
