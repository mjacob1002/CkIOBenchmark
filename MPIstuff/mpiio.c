#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
char* sequentialRead(char* filename, size_t offset, size_t num_bytes);
int main(int argc, char** argv){

	double start_time, end_time;

	int start, end;
	int error;
	int nprocs, rank;

	int length = 0;	
	
	char* buffer;

	MPI_Status status;
	MPI_File fh;
	MPI_Offset filesize;

	if(argc != 2){
		fprintf(stderr, "I need 1 argument for the file to read\n");
		exit(2);
	}
	// fprintf(stderr, "Filename to be opened: %s\n", argv[1]);
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	fprintf(stdout, "Filename: %s\n. Number of processes: %d\n.", argv[1], nprocs);	
	MPI_Barrier(MPI_COMM_WORLD); // wait for all of the processes to gather	
	start_time = MPI_Wtime(); // measure from the opening of the file
	error = MPI_File_open(MPI_COMM_WORLD, argv[1], MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
	double file_open_time = MPI_Wtime();
	if(error != MPI_SUCCESS) {
		fprintf(stderr, "Proccess %d had an error when opening %s\n", rank, argv[1]);
		MPI_Finalize();
		exit(-1);
	}

	error = MPI_File_get_size(fh, &filesize);
	if(error != MPI_SUCCESS){
		fprintf(stderr, "Proccess %d had an error when getting size of file %s\n", rank, argv[1]);
		MPI_Finalize();
		exit(-1);
	}
	// fprintf(stderr, "Processor %d says filesize is %zu\n", rank, filesize);
	length = filesize / nprocs;
	start = rank * length;
	if(rank == nprocs - 1)
		end = filesize;
	else 
		end = start + length;
	buffer = new char[(end-start) * sizeof(char) + sizeof(char)];
	if(!buffer){
		fprintf(stderr, "Proccess %d had an error when getting mallocing %d bytes\n", rank, (end-start));
		MPI_Finalize();
		exit(-1);
	}
	MPI_File_seek(fh, start, MPI_SEEK_SET);
	double read_before = MPI_Wtime();
	error = MPI_File_read(fh, buffer, end-start, MPI_BYTE, &status);
	double read_after = MPI_Wtime();
	if(error != MPI_SUCCESS){
		fprintf(stderr, "Something went wrong when process %d tried to read from %d to %d\n", rank, start, end);
		MPI_Finalize();
		exit(-1);
	}
	int num_bytes_read;
	MPI_Get_count(&status, MPI_BYTE, &num_bytes_read);
	buffer[end-start] = '\0';
	MPI_Barrier(MPI_COMM_WORLD);
	end_time = MPI_Wtime();
	if(!rank){
		fprintf(stderr, "Total time for program: %f\n", end_time-start_time);
		fprintf(stderr, "Total time for opening the file: %f\n", file_open_time - start_time);
		fprintf(stderr, "Total time for the read from file: %f\n", read_after - read_before);
		fprintf(stderr, "Total bytes read: %d\n", num_bytes_read);
		fprintf(stderr, "Total bandwidth: %f\n", (1.0 * filesize / ((1 << 30) * (end_time - start_time))));
	}
	// fprintf(stdout, "From process %d: read %zu bytes\n", rank, strlen(buffer));
	MPI_File_close(&fh);
	char* seq_buffer = sequentialRead(argv[1], start, (end - start));
	for(size_t i = 0; i < (end-start); ++i) {
		if(seq_buffer[i] != buffer[i]){
			printf("Rank %d: seq_buffer[%d]=%d, while buffer[%d] = %d\n", rank, i, (int)(seq_buffer[i]), i, (int)(buffer[i]));
			exit(5);
		}
	}
	delete[] seq_buffer;
	delete[] buffer;
	MPI_Finalize();
	return 0;

}

char* sequentialRead(char* filename, size_t offset, size_t num_bytes){
	FILE* fp = fopen(filename, "r");
	char* buffer= new char[num_bytes]; // allocate this amount of bytes
	fseek(fp, offset, SEEK_SET);
	int bytes_read = fread(buffer, 1, num_bytes,fp);
	fclose(fp);
	return buffer;
}
