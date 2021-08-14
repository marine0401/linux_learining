#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	int pid,semid;
	key_t semkey;
	if((semkey = ftok("./test.c",1)) < 0)
	{
		printf("ftok failed\n");
		exit(EXIT_FAILURE);
	}
	printf("ftok ok,semkey=%d\n",semkey);

	if((semid = semget(semkey,1 ,IPC_CREAT|IPC_EXCL|0700)) < 0)
	{
		printf("semget failed\n");
		exit(EXIT_FAILURE);
	}
	printf("semget ok, semid = %d \n",semid);

	if((semctl(semid,0,SETVAL,1)) < 0 )
	{
		printf("semctl set semval failed\n");
		exit(EXIT_FAILURE);
	}
	printf("semctl set semval ok\n");

	if((pid = fork()) < 0)
	{
		printf("fork failed \n");
		exit(EXIT_FAILURE);
	}
	else if(pid > 0 )
	{
		struct sembuf p_op_buf,v_op_buf;
		p_op_buf.sem_num = 0;
		p_op_buf.sem_op = -1;
		if(semop(semid,&p_op_buf,1) < 0)
		{
			printf("semop failed\n");
			exit(EXIT_FAILURE);
		}
		printf("father get the semaphore\n");
		sleep(3);
		printf("father release the semaphore\n");
		v_op_buf.sem_num = 0;
		v_op_buf.sem_flg = 0;
		if(semop(semid,&v_op_buf,1) < 0)
		{
			printf("semop release semaphore failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		struct sembuf p_op_buf,v_op_buf;
		sleep(1);
		printf("child wait for the semaphore\n");
		p_op_buf.sem_num = 0;
		p_op_buf.sem_op = -1;
		p_op_buf.sem_flg = 0;
		if(semop(semid,&p_op_buf,1) < 0)
		{
			printf("semop get semaphore failed \n");
			exit(EXIT_FAILURE);
		}
		printf("child get the semaphore\n");
		if(semctl(semid,0,IPC_RMID,0) < 0)
		{
			printf("semctl remove semaphore set failed\n");
			exit(EXIT_FAILURE);
		}
		
	}

	return 0;
}
