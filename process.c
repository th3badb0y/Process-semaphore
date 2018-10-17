#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main()
{
 	int i,n;
 	printf("\n pid=%d, ppid=%d",getpid(),getppid());
 	p=fork();
 	if(n == 0)
 	{
 		for(i=0;i<3;i++)
 			{
 				printf("\n child process is running,pid=%d,ppid=%d",getpid(),getppid());
 				sleep(2);
 			}
 			printf("\n child Exited\n");
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
 	
 		  
