#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
	pid_t child;
	if((child = fork()) < 0)
	{
		exit(EXIT_FAILURE);
	}else
	{
		if(child == 0)
		{
			sleep(2);
			printf("child pid = %d\n",getpid());
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			printf("father pid = %d\n",getpid());
			exit(EXIT_SUCCESS);
		}
	}
	return 0;
}
