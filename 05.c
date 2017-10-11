/* 5. Write a program to ignore the termination of process when its terminal
will close.
Hint : use SIGHUP signal & signal().*/
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{

signal(SIGHUP,SIG_IGN);
printf("program start.....\n");
while(1);
return 0;
}
