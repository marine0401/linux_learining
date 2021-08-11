#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define FIFO_SERVER "./myfifo"


int main(int argc , char **argv)
{
	int fd;
	char w_buf[100];
	int nwrite;
	if((mkfifo(FIFO_SERVER,O_CREAT|O_EXCL|O_RDWR) < 0)&&(errno != EEXIST))
	{
		printf("cannot create fifoserver\n");
	}

	fd = open(FIFO_SERVER,O_WRONLY ,0);
	if(fd == -1)
	{
		perror("open failure");
		exit(1);
	}
	if(argc == 1)
	{
		printf("Please send something\n");
		exit(-1);
	}
	strcpy(w_buf,argv[1]);

	if((nwrite = write(fd,w_buf,100)) == -1)
	{
		if(errno == EAGAIN)
		{
			printf("The FIFO has not been read yet. Please try later\n");
		}
		
	}
	else
	{
		printf("write %s to the FIFO\n",w_buf);
	}
	close(fd);

	return 0;
}
