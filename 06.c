/* 6. Write a program to install ISR(handler) for SIGINT and SIGQUIT .
Restore the SIGINT to default after 3 times occurrence.SIGQUIT to
default after 5 times occurrence.*/
#include<signal.h>
#include<stdio.h>
void func1(int);
void func2(int);
int count1=1;
int count2=1;
int main(void)
{
signal(SIGINT,func1);
signal(SIGQUIT,func2);
printf("Program started........\n");

while(1);
return 0;
}

void func1(int n)
{
if(count1==3)
signal(SIGINT,SIG_DFL);
count1++;
}

void func2(int n)
{
if(count2==5)
signal(SIGQUIT,SIG_DFL);
count2++;
}
