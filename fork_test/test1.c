#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	pid_t child;
	if((child = fork()) == -1)
	{
		printf("error");
		exit(1);
	}else
	{
		if(child == 0)
		{
			printf("child pid ");
			exit(1);
		}else
		{
			printf("father pid ");
			exit(1);
		}
	}
	return 0;
}
