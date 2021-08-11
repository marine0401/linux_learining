#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	int pipe_fd[2];
	pid_t child;
	char buf[100];
	int r_num;
	//memset(buf,0,sizeof(buf));
	
	if(pipe(pipe_fd) < 0)
	{
		printf("pipe create error\n");
		exit(EXIT_FAILURE);
	}
	if((child=fork()) == 0)
	{
		printf("\n");
		close(pipe_fd[1]);
		sleep(2);
		if((r_num = read(pipe_fd[0],buf,100)) > 0)
		{
			printf("%d numbers read from the pipe is %s",r_num,buf);
		}
		close(pipe_fd[0]);
		exit(0);
	}else if(child > 0)
	{
		printf("\n");
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"hello",5) > 0)
		{
			printf("write1 hello \n");
		}
		if(write(pipe_fd[1],"pipe",4) >0)
		{
			printf("write2 pipe\n");
		}
		close(pipe_fd[1]);
		exit(EXIT_SUCCESS);
	}else
	{
		exit(EXIT_FAILURE);
	}


	return 0;
}



