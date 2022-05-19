#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define DELIM " \t\r\n"
/**
* main- a simple shell that prints the path entered
* @argv: array of command line arguments
* Return: run the command entered by the user
*/
int execute(char **argv);

int execute(char **argv)
{
	pid_t parent_id;

	parent_id = fork(); /* handles new instances in the process*/

	if (parent_id == 0)
	{	
		if (execve(argv[0], argv, NULL) == -1)
		{	
			perror("./shell-practice"); /*path of the directory*/
		}
	}
	else if (parent_id < 0)
	{
		printf("Error in forking");
	}
	else
	{
		wait(&parent_id);
	}

	return (1);
}


int main(void)
{
	char *token;
	int i = 1;
	
	do
	{
		char *string;
		size_t size = 1024;
		char *argv[] = {NULL, NULL};

		string = (char *) malloc(size);
		printf("cisfun$ ");

		getline(&string, &size, stdin);

		if (!string)
		{
			return (0);
		}

		token = strtok(string, DELIM);
	
		if (token == NULL)
		{
			argv[0] = "";
		}
		else
		{
			argv[0] = strdup(token); /*stores the token*/
		}
	
		token = strtok(NULL, DELIM);
		printf("token - %s\n", token);
		printf("argv[0] - %s\n", argv[0]);

		i = execute(argv);
		free(string);
	}

	while (i);
	return (0);

}	
