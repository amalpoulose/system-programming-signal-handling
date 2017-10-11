/* 2. Create a watch dog timer in parent which should watch T.A.T of its
child and terminate the child.
Condition: The child have random delay(1-10 sec)
If the child take more than 5 sec then parent terminate it.
Hint : fork(),sleep?(),kill(),alarm().*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(void)
{
	int r_value,cid;
	srand(getpid());
	r_value=rand()%10+1;
        printf("Delay = %d\n",r_value);
	if((cid=fork())==0)
	{
		printf("child starts......\n");
		sleep(r_value);
		printf("child ends\n");
		exit(0);
	}
	else
	{
		alarm(6);
		void my_isr(int n)
		{
			kill(cid,9);
                        printf("Child Terminated Forcefully\n");
		}
		signal(SIGALRM,my_isr);
		wait(0);
		signal(SIGALRM,SIG_IGN);
	}
	return 0;
}
