#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void *thread(void *str)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		sleep(2);
		printf("This in the thread : %d \n",i);
	}
	return (void *)0;
}
int main(int argc, char * argv[])
{
	pthread_t pth;
	int i;

	int ret = pthread_create(&pth,NULL,thread,NULL);
	printf("The main process will be to run,but will be blocked soon\n");

	pthread_join(pth,NULL);
	printf("thread was exit\n");
	sleep(1);
	for(i = 0; i < 3; i++)
	{
		printf("This is in the main %d \n",i);
	}
	return 0;
}
