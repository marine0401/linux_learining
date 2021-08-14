#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

struct menber
{
	int a;
	char *s;
};

void *create(void *);

int main(int argc,char *argv[])
{
	pthread_t tidp;
	int error;
	struct menber *b;

	b = (struct menber*)malloc(sizeof(struct menber));
	b->a = 4;
	b->s = "zieckey";
	error = pthread_create(&tidp,NULL,create,(void *)b);
	if(error)
	{
		printf("pthread is not create ...\n");
		return -1;
	}
	sleep(1);
	printf("pthread is created..\n");
	return 0;
}


void *create(void *arg)
{
	struct menber *temp;
	temp = (struct menber*)arg;
	printf("menber->a = %d \n",temp->a);
	printf("menber->s = %s\n",temp->s);
	return (void *)0;
}


