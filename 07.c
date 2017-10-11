/* 7. Write a program to create 3 child process from common parent use
random delay between 1 to 10 sec in each child. Use alarm() in parent
in such a manner that
Child1 should not exceeds more than 4 sec.
Child2 should not exceeds more than 6 sec.
Child3 should not exceeds more than 8 sec.*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(void)
{
	int r_value,cid[3],i,delay=4,temp,s;
	srand(getpid());
	r_value=rand()%10+1;
        printf("Delay = %d\n",r_value);

	for(i=0;i<3;i++)
	{
		if((cid[i]=fork())==0)
		{
			printf("child %d starts......\n",i+1);
			sleep(r_value);
			printf("child %d ends\n",i+1);
			exit(0);
		}
		else;
	}
        i=0;
	void my_isr(int n)
	{
		kill(cid[i],9);
		printf("Child %d Terminated Forcefully\n",i+1);
	}
	alarm(delay+1); // in case delay = 4
        while(i<3)
       {
        temp=0;
	signal(SIGALRM,my_isr);
	wait(0);
	signal(SIGALRM,SIG_IGN);
        if(delay-r_value>0)
             temp=delay-r_value;
        delay+=2;
        i++;
        alarm(2+temp);
       }       
return 0;
}
