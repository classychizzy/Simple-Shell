#include <stdio.h>
#include <unistd.h>
/**
* main- a function that tests the execve command
* Return: -1 on error
*/
int main(void)
{
	char path[] = "/bin/ls";
	char *argv[] = {"/bin/ls", "-l", "/home/", NULL};
	char *env[] = {NULL};

	printf("start of execve call \n");

	if (execve(path, argv, env) == -1)
	{
		perror("could not execute execve");
	}

	printf("something is wrong");
	return (0);
}
