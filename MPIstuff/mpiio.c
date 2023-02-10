#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

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
		fprintf(stderr, "I need 2 arguments\n");
		exit(2);
	}
	// fprintf(stderr, "Filename to be opened: %s\n", argv[1]);
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Barrier(MPI_COMM_WORLD); // wait for all of the processes to gather	
	start_time = MPI_Wtime(); // measure from the opening of the file
	error = MPI_File_open(MPI_COMM_WORLD, argv[1], MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
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
	buffer = malloc((end-start) * sizeof(char) + sizeof(char));
	if(!buffer){
		fprintf(stderr, "Proccess %d had an error when getting mallocing %d bytes\n", rank, (end-start));
		MPI_Finalize();
		exit(-1);
	}
	MPI_File_seek(fh, start, MPI_SEEK_SET);
	error = MPI_File_read(fh, buffer, end-start, MPI_BYTE, &status);
	if(error != MPI_SUCCESS){
		fprintf(stderr, "Something went wrong when process %d tried to read from %d to %d\n", rank, start, end);
		MPI_Finalize();
		exit(-1);
	}

	buffer[end-start] = '\0';
	MPI_Barrier(MPI_COMM_WORLD);
	end_time = MPI_Wtime();
	if(!rank){
		fprintf(stderr, "Total time: %f\n", end_time-start_time);
	}
	// fprintf(stdout, "From process %d: read %zu bytes\n", rank, strlen(buffer));
	MPI_File_close(&fh);

	MPI_Finalize();
	return 0;

}
