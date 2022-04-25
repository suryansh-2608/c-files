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
	char temp_store[100];
	void * shared_mem;
	shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
	printf("The key of the created shared memory is %d\n", shmid);
	shared_mem = shmat(shmid, NULL, 0);
	printf("The process created is stored at the address %p\n", shared_mem);
	printf("Please enter some data so as to store it in the created shared memory: \n");
	read(0, temp_store, 100);
	strcpy(shared_mem, temp_store);
	shmdt(shared_mem);
}
