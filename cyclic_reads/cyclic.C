#include "cyclic.decl.h"
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
	size_t num_readers = 1;
	size_t num_io_buffers = 32;
	size_t size_chunks = 64 * 1024 * 1024; // 64MB
	std::string TEST_FILE;
	std::string dump_file;
	// std::string TEST_FILE;
public:
	Main(CkArgMsg* msg){
		traceRegisterUserEvent("register memory", 10);
		if(msg -> argc < 3) {
			CkPrintf("Usage: cyclic <test_file> <number of pes> <number of io buffers(optional)> <number of client readers pe pe (optioal)>\n");
			CkExit();

		}
		TEST_FILE = std::string(msg -> argv[1]); // name of the test file
		num_pes = atoi(msg -> argv[2]); // the number of pes
		if(msg -> argc > 3){
			num_io_buffers = atoi(msg -> argv[3]); // number of I/O buffers	
		}
		if(msg -> argc > 4){
			num_readers= atoi(msg -> argv[4]); // the number of readers to use
		}	
		if(msg -> argc > 5){
			size_chunks = atoi(msg -> argv[5]); // the size of chunk to use
			CkPrintf("The parameter passed in is the following: msg -> argv[5]=%s\n", msg -> argv[5]);
		}
		if(msg -> argc > 6) 
			dump_file = std::string(msg -> argv[6]);
		CkPrintf("Args: TEST_FILE=%s, num_pes=%zu, num_io_bufers = %zu, num_readers=%zu, size_chunk=%zu, dump_file=%s\n", msg -> argv[1], num_pes, num_io_buffers, num_readers, size_chunks, dump_file.c_str());
		std::ifstream ifs;
		ifs.open(TEST_FILE);
		ifs.seekg(0, std::ios::end);
		file_size = ifs.tellg();
		ifs.close();
		char* temp = new char[size_chunks];
		for(int i = 0; i < size_chunks; ++i)
			temp[i] = ('a' + (i % 32));
		double b4_sort = CkWallTimer();
		std::string s(temp, size_chunks);
		std::sort(s.begin(), s.end());
		for(int i = 1; i < s.size(); ++i)
		 	CkEnforce(s[i] >= s[i-1]);
		double after = CkWallTimer();
		CkPrintf("Sample time for sorting 64MB: %f\n", (after - b4_sort));
		thisProxy.startReading();
	}
	// returns a buffer of a sequential read so that the parallel read at offset with number of bytes length can be verified
	char* sequentialRead(size_t offset, size_t bytes){
		char* buffer = new char[bytes + 1];
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
		buffer[bytes] = 0;
		ifs.close();
		return buffer;
	}

	void doneReading(CkReductionMsg* msg){
		end_time = CkWallTimer();
		std::cerr << "Just finished reading\n";
		// CkCallback cb(CkIndex_Main::logging(0), mainProxy);
		traceEnd(); // end the trace
	//	CkPrintf("About to try verifying the full read\n");
	//	readers.verifyFullFileRead(TEST_FILE, file_size, num_readers_per_pe * num_pes); // make sure all the reads were correct
		// mainProxy.logging(0);
		
		CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		Ck::IO::closeReadSession(current_session, cb);
		CkPrintf("Total time: %f\n", end_time - start_time);
	}

	void logging(CkReductionMsg* msg){
		end_time = CkWallTimer();
		std::cerr << "Just finished reading; about to perform loggign\n";
		traceEnd();
		CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		Ck::IO::closeReadSession(current_session, cb);
		CkPrintf("Total time: %f\n", end_time - start_time);
		FILE* fp = fopen(dump_file.c_str(), "aw+");
		double total_time = end_time - start_time;
		CkPrintf("About to log the events in %s\n", dump_file.c_str());
		fprintf(fp, "Total time: %f\n", end_time - start_time);
		fprintf(fp, "Throughput: %f\n", (file_size / total_time));
		fclose(fp);
	}
};

// object that is used to enact the parallel reads
struct Reader : public CBase_Reader {
	Reader_SDAG_CODE;
	Ck::IO::ReadCompleteMsg* og_msg = 0;
	size_t _read_size = 1024 * 1024 * 64;
	size_t my_offset;
	size_t _file_size;
	std::string testing_file;
	size_t _num_chares;
	Ck::IO::Session _session;
public:
	Reader(Ck::IO::Session session, size_t file_size, size_t read_size, size_t offset, size_t num_chares){
		// CkPrintf("Client %d has been created\n", thisIndex);
		_session = session;
		_read_size = read_size;
		_num_chares = num_chares;
		my_offset = offset + thisIndex * read_size;
		_file_size = file_size;
		#ifdef TEMP_DEBUG
		#endif
		// ckout << "My offset for reader " << thisIndex << " is " << my_offset << endl;
		CkCallback test_read_cb(CkIndex_Reader::testRead(0), thisProxy[thisIndex]);	
		// CkPrintf("From Reader[%d] before issuing read: _bytes=%zu, my_offset=%zu\n", thisIndex, _bytes, my_offset); 
		size_t bytes = std::min(read_size, file_size - my_offset);
		Ck::IO::read(session, bytes, my_offset, test_read_cb);
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
		testing_file = test_file;
		char* sequence = sequentialRead(my_offset, num_bytes_to_read);
		if(!thisIndex) CkPrintf("Reader 0 verification: starting verification of the data\n");
		for(size_t i = 0; i < num_bytes_to_read; ++i){
			if(og_msg -> data[i] != sequence[i]){
				CkPrintf("Reader[%d]: og_msg -> data[%d]=%c; sequence[%d]=%c\n", thisIndex, i, (og_msg -> data[i]), i, sequence[i]);
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

#include "cyclic.def.h"
