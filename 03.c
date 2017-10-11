/* 3. Create a function named “find-isr”,which when calling by passing an
interrupt number then it should inform the action of that signal in
current program.
Signal action----defaulted
o/p->Ignore
userdefine.
Hint : use signal( ) function to return value.*/
#include<stdio.h>
#include<signal.h>

int main(int argc , char **argv)
{
	if(argc!=2)
	{
		printf("Usage : ./a.out sig_no\n");
		return;
	}
	int sig_no;
	void (*action)(int);
	sig_no=atoi(argv[1]);
	action=signal(sig_no,SIG_IGN);
	signal(sig_no,action);
	if(action==SIG_DFL)
		printf("Terminate\n");
	else if(action==SIG_IGN)
		printf("Ignore\n");
	else
		printf("User defined\n");
	return 0;
}

