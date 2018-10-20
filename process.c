#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main()
{
 	int i,n;
 	printf("\n pid=%d, ppid=%d",getpid(),getppid());
 	p=fork();//PROCESS CREATION
 	if(n == 0)
 	{
 		for(i=0;i<3;i++)
 			{
 				printf("\n Child process is running,pid=%d,ppid=%d",getpid(),getppid());
 				sleep(2);
 			}
 			printf("\n Child Exited\n");
 			sleep(2);
 	}
 	else if(n>0)
 	{
 		for(i=0;i<6;i++)
 			{
 		 		printf("\n Parent process is running pid=%d,ppid=%d",getpid(),getppid());
 		 		sleep(2);
 		 	}
 	}
 	else
 		printf("\n Error in creating child process");
 }
 	
 		  
