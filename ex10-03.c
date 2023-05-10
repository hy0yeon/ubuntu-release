#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void int_handle(int);

int num = 0;

int main()
{
		static struct sigaction act;
		act.sa_handler = int_handle;
		sigfillset(&(act.sa_mask));
		sigaction(SIGINT, &act, NULL);	//if sigint do act, no oldact	you can find sigint in man 7 signal

		while(1)
		{
				printf("I'm sleepy...\n");
				sleep(1);
				if(num >= 3)
						exit(0);
		}
}

void int_handle(int signum)	//handler
{
		printf("SIGINT:%d\n", signum);
		printf("int handle called %d times\n", ++num);
}
