#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void create_file(char *);
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("你没有传入足够的参数\n");
	}
	else
	{
		create_file(argv[1]);
		exit(EXIT_SUCCESS);
	}
}
void create_file(char *filename)
{
	if(creat(filename,0666)<0)
	{
		exit(EXIT_FAILURE);
	}else
	{
		printf("create file %s success",filename);
	}
}
