#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
	int count = 0;
	pid_t child;
	//创建一个子进程
	if((child = vfork()) == -1)
	{
		exit(0);
	}else
	{
		//在子进程中改变count的值，在父进程中验证是否共享内存空间。
		if(child == 0)
		{
			count++;
			printf("child pid = %d\n",getpid());
			exit(0);

		}else
		{
			printf("father pid = %d,count = %d\n",getpid(),count);
			exit(0);
		}
	}
	return 0;
}
