#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		perror("你没有传入文件名\n");
		exit(EXIT_FAILURE);
	}
	execl("./file_creat","file_creat",argv[1],(char*)0);
	perror("execl error!\n");
	
}
