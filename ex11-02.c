#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE	512

int main()
{
		char msg[SIZE];
		int filedes[2];
		int i;

		if(pipe(filedes) == -1) {
				printf("fail to claa pipe()\n");
				exit(1);
		}

		for(int i = 0; i < 3; i++) {
				printf("input a message\n");
				fgets(msg, SIZE, stdin);
				write(filedes[1], msg, SIZE);	//filedes[1] is write
		}
		printf("\n");
		for(int i = 0; i < 3; i++) {
				read(filedes[0], msg, SIZE);	//filedes[0] is read
				printf("%s", msg);
		}
}
