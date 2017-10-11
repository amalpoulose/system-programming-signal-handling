/* 8. Write a Program parent has to get the data from user and store the
data in file.after that
parent process will send one signal to child process.child process after
receving the
signal,open the file and convert data to oppsite case and store again in
same file.
Hint : Use pause() in child process.
Use signal num 10(usersignal) in parent.*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>
int main(void)
{
	int cid;
	FILE *fp;
	if((cid=fork())==0)
	{
		void my_isr(int n)
		{
			char ch;
			fp=fopen("filen","r+");
			while((ch=fgetc(fp))!=EOF)
			{
				if((ch>64 && ch<91)||(ch>96 && ch<123))
				{
					ch=ch^32;
					fseek(fp,-1,SEEK_CUR);
					fputc(ch,fp);
				}
			}
			fclose(fp);
			printf("Done\n");
			exit(0);
		}
		signal(10,my_isr);
		pause();
	}
	else
	{
		fp=fopen("filen","w");
		char s[50];
		printf("enter String : ");
		scanf("%[^\n]",s);
		fputs(s,fp);
		fclose(fp);
		kill(cid,10);
		wait(0);
	}
	return 0;
}
