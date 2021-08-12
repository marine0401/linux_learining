#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void my_fun(int);

int main(int argc,char *argv[])
{
	printf("waiting for signal SIGBUS\n");
	signal(SIGBUS, my_fun);
	pause();
	exit(0);
	return 0;
}
void my_fun(int sign_no)
{
	if(sign_no == SIGBUS)
	{
		printf("I have get SIGBUS\n");
	}
}
