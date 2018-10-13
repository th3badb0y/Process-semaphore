#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main()
{
 	int i,p;
 	printf("\n pid=%d, ppid=%d",getpid(),getppid());
 	p=fork();
 	if(p == 0)
 	{
 		for(i=0;i<3;i++)
 			{
 				printf("\n Child process running,pid=%d,ppid=%d",getpid(),getppid());
 				sleep(2);
 			}
 			printf("\n Child Exited\n");
 			sleep(2);
 	}
 	else if(p>0)
 	{
 		for(i=0;i<6;i++)
 			{
 		 		printf("\n Parent process running pid=%d,ppid=%d",getpid(),getppid());
 		 		sleep(2);
 		 	}
 	}
 	else
 		printf("\n Error in creating chid process");
 }
 	
 		  
