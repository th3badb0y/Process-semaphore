#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<error.h>
main()
{
	int sid,val,val1;
	key_t key=ftok("eg.txt",'a');
	struct sembuf s[]={0,-1,0};
	
	if((sid = semget(key,1,IPC_CREAT | 0666))== -1)
		printf("error");
	else
	{
		printf("Semaphore created\n");
		printf("Semaphore ID is %d\n",sid);
	}
	
	if(semctl(sid,0,SETVAL,1)==0)
		printf("Semaphore initialized as 1\n");
	if((val1 = semctl(sid,0,GETVAL))>0)
		printf("Value of semaphore is %d\n",val1);
	
	if((val = semop(sid,&s[0],1)) == 0)
		printf("Semaphore locked\n");
	val1=semctl(sid,0,GETVAL);
	printf("Value of semaphore after locking id %d\n",val1);
	
	s[0].sem_op=1;
	semop(sid,&s[0],1);
	printf("Semaphore unlocked\n");
	val1=semctl(sid,0,GETVAL);
	printf("Value after unlocking is %d\n",val1);
	
	if((semctl(sid,0,IPC_RMID) == 0))
	printf("Closed the semaphore\n");
}
		
