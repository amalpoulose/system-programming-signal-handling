/* 1. Write a program to deliver the alarm signal periodically after (n-1)sec
from the last
interrupt.
Hint : Start first alarm at 10 sec then next alarm at 9sec so on up to
n=0 terminate .*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int seconds=10;
void my_isr(int n)
{       
        printf("Alarm clock\n");   
	if(seconds==2)
		signal(SIGALRM,SIG_DFL);
	seconds--;
        printf("Setting alarm for %d second\n",seconds);
        alarm(seconds);
}

int main(void)
{
	signal(SIGALRM,my_isr);
        printf("Setting alarm for %d second\n",seconds);
        alarm(seconds);
        while(1);
	return 0;
}
