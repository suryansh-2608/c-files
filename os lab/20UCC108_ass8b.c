//Suryansh Bhardwaj
//20UCC108
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
int main()
{
	int shmid;
	void * shared_mem;
	shmid = shmget((key_t)2345, 1024, 0666);
	printf("The key of the created shared memory is %d\n", shmid);
	shared_mem = shmat(shmid, NULL, 0);
	printf("The process created is stored at the address %p\n", shared_mem);
	printf("The data that was written in the shared memory with help of ass8a.c is: %s\n", (char *)shared_mem);
	shmdt(shared_mem);
}
