/* 4. Write a program to remove the zombie.
Hint : Use SIGCHLD &signal( ).*/
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int pid;
void func(int n)
{
wait(0);
printf("Zombie of Id %d is removed\n",pid);
}
int main(void)
{
signal(SIGCHLD,func);
printf("program start.....\n");
if((pid=fork())==0)
{
 sleep(10);
 printf("child\n");
}
else
{
printf("parent continue....\n");
while(1);
}
return 0;
}
