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
	size_t num_readers_per_pe = 1;
	size_t mbs_per_buffer = 64*1024*1024;	// 64 MBs
	std::string TEST_FILE;
	// std::string TEST_FILE;
public:
	Main(CkArgMsg* msg){
		traceRegisterUserEvent("register memory", 10);
		TEST_FILE = std::string(msg -> argv[1]); // power of the file
		num_pes = atoi(msg -> argv[2]); // the number of pes
		if(msg -> argc > 3){
			size_t power_of_mbs = atoi(msg -> argv[3]); // 2*n MBs
			size_t exp = power_of_mbs + 20;
			mbs_per_buffer = 1;
			mbs_per_buffer <<= exp;
		}
		if(msg -> argc > 4){
			num_readers_per_pe = atoi(msg -> argv[4]);
		}	
		std::ifstream ifs;
		ifs.open(TEST_FILE);
		ifs.seekg(0, std::ios::end);
		file_size = ifs.tellg();
		ifs.close();
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
		readers.verify(TEST_FILE); // make sure all the reads were correct
		// mainProxy.logging(0);
		
		// CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		// Ck::IO::closeReadSession(current_session, cb);
		// CkPrintf("Total time: %f\n", end_time - start_time);
	}

	void logging(CkReductionMsg* msg){
		CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		Ck::IO::closeReadSession(current_session, cb);
		CkPrintf("Total time: %f\n", end_time - start_time);
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
		my_offset = offset + thisIndex * bytes;
		_bytes = file_size / num_chares;	
		if(thisIndex == num_chares - 1) _bytes = std::min(_bytes, file_size - my_offset);
		// ckout << "My offset for reader " << thisIndex << " is " << my_offset << endl;
		CkCallback test_read_cb(CkIndex_Reader::testRead(0), thisProxy[thisIndex]);	
		Ck::IO::read(session, _bytes, my_offset, test_read_cb);
	}

	char* sequentialRead(size_t offset, size_t bytes){
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

};

#include "iotest.def.h"
