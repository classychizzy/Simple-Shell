#include <stdio.h>
#include <unistd.h>
/**
* main- a function that creates a new child process
* Return: 0 on success, -1 on failure
*/
int main (void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork \n");

	pid = fork();
	if (pid == -1)
	{
	perror("Error!");
	return (-1);
	}

	printf("After fork\n");
	my_pid = getpid();
	printf("my pid is now %u\n:", my_pid);
	return (0);
}
