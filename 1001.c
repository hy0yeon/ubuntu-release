#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main()
{
		sigset_t set;
		int count = 5;

		sigemptyset(&set);	//init, recommended
		sigfillset(&set);	//fill set

		sigprocmask(SIG_BLOCK, &set, NULL);	//set to setblock. block all

		while(count)
		{
				printf("don't disturb me (%d)\n", count--);
				sleep(1);
		}
		sigemptyset(&set);	//empty set
		sigaddset(&set, SIGINT);	//sigint to set. will unblock only sigint in the next line
		sigprocmask(SIG_UNBLOCK, &set, NULL);	//set to unblock. unblock sigint

		printf("you did not disturb me!!\n");	//not printed if ctrl c pressed before unblock
}
