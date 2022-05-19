#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* main- fork and wait
* Return: 0 on success
*/
int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		printf("wait for me \n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
	
