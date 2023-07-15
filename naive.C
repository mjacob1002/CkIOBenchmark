#include "naive.decl.h"
#include <vector>
#include <fstream>
#include <fcntl.h>
#include <algorithm>

CProxy_Main mainProxy;


class Main : public CBase_Main {
	Main_SDAG_CODE;
	CProxy_Reader readers; // holds the array of readers
	size_t num_reads_done = 5; // initialize the number of reads to 5 and count down
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
		if(msg -> argc < 6) {
			CkPrintf("Usage: iotest <test_file> <number of pes> <number of io buffers(optional)> <number of client readers> <dump_file>\n");
			CkExit();

		}
		TEST_FILE = std::string(msg -> argv[1]); // power of the file
		num_pes = atoi(msg -> argv[2]); // the number of pes
		if(msg -> argc > 5){
			num_io_buffers = atoi(msg -> argv[3]);
			num_readers = atoi(msg -> argv[4]);
			dump_file = std::string(msg -> argv[5]);
		}	
		CkPrintf("Args: TEST_FILE=%s, num_pes=%zu, num_io_buffers(unused)=%zu, num_readers=%zu, dump_file=%s\n", TEST_FILE.c_str(), num_pes, num_io_buffers, num_readers, dump_file.c_str());
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
		// mainProxy.logging(0);
		// CkCallback cb(CkIndex_Main::postClose(0),mainProxy);
		CkPrintf("Total time: %f\n", end_time - start_time);
		FILE* fp = fopen(dump_file.c_str(), "aw+");
		fprintf(fp, "Total time: %f\n", end_time - start_time);
		fprintf(fp, "Throughput: %f\n", file_size / (end_time - start_time));
		fclose(fp);
		CkExit();
	}

};

// object that is used to enact the parallel reads
struct Reader : public CBase_Reader {
	Reader_SDAG_CODE;
	char* _buffer = 0;
	size_t _bytes;
	size_t my_offset;
public:
	Reader(std::string test_file, size_t file_size, size_t bytes, size_t offset, size_t num_chares){
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
		_buffer = new char[_bytes];
		FILE* fp = fopen(test_file.c_str(), "r");
		if(!fp){
			CkPrintf("The file pointer is null on %zu\n", thisIndex);
		}
		fcntl(fileno(fp), F_SETFD, O_DIRECT);
		fseek(fp, my_offset, SEEK_SET);
		size_t num_bytes_read = fread(_buffer, 1, _bytes, fp);
		if(!num_bytes_read){
			if(feof(fp)) CkPrintf("End of file reached\n");
			else CkPrintf("WHY IS THIS READING 0 BYTES\n");
		}
		if(num_bytes_read != _bytes) 
			CkPrintf("Reader[%d]: num_bytes_read=%zu; _bytes=%zu\n", thisIndex, num_bytes_read, _bytes);
		CkEnforce(num_bytes_read == _bytes);	
		fclose(fp);
		CkCallback cb(CkReductionTarget(Main, doneReading), mainProxy);
		contribute(cb);
	}

};

#include "naive.def.h"
