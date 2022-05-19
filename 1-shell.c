<<<<<<< HEAD
#include "shell.h"
#define TOKEN_DELIM " \t\r\n"
/**
* execute - A function that executes a process
* @argv: argument variables
* Return: (1) on success
*/
int execute(char **argv);

int execute(char **argv)
{
	pid_t main_id;

	main_id = fork();
	if (main_id == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell: ");
		}
	}
	else if (main_id < 0)
	{
		printf("Error in forking");
	}
	else
	{
		wait(&main_id);
	}
	return (1);
}
/**
* main- a function that returns path entered by user
* Return: 0 on success.
*/
int main(void)
{
	int i = 1;
	char *token;

	do {
		char *str;
		ssize_t num;
		char *argv[] = {NULL, NULL};
		size_t n = NULL;

		printf("$ ");
		str = malloc(sizeof(char) * n);
		if (!str)
		{
			return (0);
		}
		num = getline(&str, &n, stdin);
		printf("%ld", num);
		token = strtok(str, TOKEN_DELIM);
		printf("\ntoken - %s\n", token);

		if (token == NULL)
		{
			argv[0] = "";
		}
		else
		{
			argv[0] = strdup(token);
		}

		printf("argv[0] - %s\n", argv[0]);
		token = strtok(NULL, TOKEN_DELIM);
		printf("token - %s\n", token);
		printf("argv[0] - %s\n", argv[0]);
		i = execute(argv);
		free(str);
	}

	while (i);

	return (0);
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define TOKEN_DELIM " \t\r\n"


/**
 * main - A function that prints all the arguments
 *
 * @ac: argument count
 * @av: argument variables
 *
 * Return: always sucess.
 */

int execute(char** argv);


int execute(char** argv)
{
    pid_t main_id;

    main_id = fork();

    if (main_id == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("./shell: ");
        }

    }

    else if (main_id < 0)
    {
        printf("Error in forking");
    }

    else
    {
        wait(&main_id);
    }

    return (1);
}


int main(void)
{

    int i = 1;

    char *token;


    do 
    {
        char *str;

        int num;

        char *argv[] = {NULL, NULL};

        size_t n = 1024;

        printf("#cisfun$ ");

        str = malloc(sizeof(char) * n);

        if (!str)
        {
            return (0);
        }

        num = getline(&str, &n, stdin);

        printf("%s", num);

        //NB: the geline add newline to the gotten strin
        //hence why i used a string token to delimit ('\n') newline.

        token = strtok(str, TOKEN_DELIM);

        printf("\ntoken - %s\n", token);

        
        if (token == NULL)
        {
            argv[0] = "";
        }

        else
        {
            argv[0] = strdup(token);
        }

        printf("argv[0] - %s\n", argv[0]);

        token = strtok(NULL, TOKEN_DELIM);

        printf("token - %s\n", token);

        printf("argv[0] - %s\n", argv[0]);

        i = execute(argv);

        free(str);
    }

    while (i);

    return (0);
}
>>>>>>> parent of d82c32f... updated file
