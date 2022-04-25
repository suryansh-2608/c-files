#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid1;
	int arr[21];
	int sum_parent = 0;
	for(int i = 1; i<20; i++)
	{
		arr[i-1] = i;
		if(i%2==0)
			sum_parent += i;
	}
	
	printf("%d\n in parent process \n", sum_parent);
	
	pid1 = fork();
	
	if(pid1 == 0)
	{
		sleep(2);
		int arr_2[21];
		int sum_child = 0;
		for (int i = 1; i<20; i++)
		{
			arr_2[i-1] = i;
			if(i % 2 == 1)
				sum_child += i;
		}
		printf("%d \n in child process \n", sum_child);
		
		printf("child[1] -> pid = %d and ppid = %d\n", getpid(), getppid());
	}
	return 0;
}
