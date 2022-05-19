#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
* main- a function that uses fork, wait and execve
*Return: pid of the process
*/
int main(void)
{
	int i;
	int status;
	char *argv[] = {"/tmp", "ls", "-l", "NULL"};
	char *envp[] = {"NULL"};
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("child process created and pid is: %d\n", getpid());

		for (i = 0;i < 5;)
		{
			printf(" child process number %d\n", i);

			execve(argv[0], argv, envp);
			i++;	
		}
	}
	else if (pid > 0)
	{
		printf("This is the parent process and pid is: %d\n", getpid());

	wait(&status);
	
	printf("a new child is born\n");
	}
	else
	{
		perror("error was generated \n");
		return (-1);
	}

	return (0);
}
