#include <unistd.h>
#include <stdio.h>

int main()
{
		printf("before executing ls -l\n");
		execl("/bin/ls", "ls", "-l", (char *)0)	//(char *)0 	null pointer because it's a string
		printf("after executing ls -l\n");
}
