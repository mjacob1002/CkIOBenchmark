#include "iotest.decl.h"
#include <vector>
#include <fstream>
#define TEST_FILE "large_test.txt"
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
public:
	Main(CkArgMsg* msg){
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
		int pos = 0;
		std::ifstream ifs(TEST_FILE);
		ifs.seekg(offset);

		while(pos < bytes){
			buffer[pos++] = ifs.get();
		}
		buffer[bytes] = 0;
		ifs.close();
		return buffer;
	}

	void doneReading(CkReductionMsg* msg){
		CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		double end_time = CkWallTimer();
		CkPrintf("Total time: %f\n", end_time - start_time);
		Ck::IO::closeReadSession(current_session, cb);
	}

};

// object that is used to enact the parallel reads
struct Reader : public CBase_Reader {

	Reader_SDAG_CODE;
public:
	Reader(Ck::IO::Session session, size_t bytes, size_t offset, CkCallback after_read){
		size_t my_offset = offset + thisIndex * bytes;
		// ckout << "My offset for reader " << thisIndex << " is " << my_offset << endl;
		CkCallback test_read_cb(CkIndex_Reader::testRead(0), thisProxy[thisIndex]);	
		Ck::IO::read(session, bytes, my_offset, test_read_cb); 
	}

};

#include "iotest.def.h"
#undef TEST_FILE
