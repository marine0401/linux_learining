#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	pid_t child;
	if((child = fork()) == -1)
	{
		printf("error");
		exit(0);
	}else
	{
		if(child == 0)
		{
			printf("child pid = %d\n",getpid());
			exit(0);
		}else
		{
			printf("father pid = %d\n",getpid());
			exit(0);
		}
	}
	return 0;
}
