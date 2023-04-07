#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
		pid_t pid;
		int n;

		scanf("%d", &n);

		pid = fork();

		if(pid == 0)
		{
				int result;
				for(int i = 1; i <= n; i++)
				{
						result = i * n;
				}
				printf("%d\n", result);
		}

		else if(pid > 0)
		{
				int result;
				for(int i = 0; i <= n; i++)
				{
						result = i + n;
				}
				printf("%d\n", result);
		}

		else
				printf("fail to fork\n");
}
