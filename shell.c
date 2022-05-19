#include "main.h"

#define TOKEN_DELIM " \t\r\n"
#define BUFFER 1024


/**
 * execute - A function that execute the shell
 *
 * @argv: argument variables
 *
 * Return: (1).
 */

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
 * tokens - A function that tokenize an input string
 * based on specific delimiters
 *
 * @str: the inputted string
 *
 * Return: tokenized string.
 */


char **tokens(char **str)
{
	char **total_token;

	char *token;

	int index = 0;

	total_token = malloc(BUFFER * sizeof(char *));

	while (!total_token)
	{
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(*str, TOKEN_DELIM);

	printf("\ntoken - %s\n", token);


	while (token != NULL)
	{
		total_token[index] = token;
		index++;
		token = strtok(NULL, TOKEN_DELIM);
	}
	total_token[index] = NULL;

	return (total_token);
}



/**
 * main - A function for the shell task
 *
 * Return: always sucess.
 */


int main(void)
{

	int i = 1;

	int num;


	do {
		char *str;

		char **tokenized;

		size_t elem = 1024;

		printf("#cisfun$ ");

		str = malloc(sizeof(char) * BUFFER);

		if (!str)
		{
			return (0);
		}

		num = getline(&str, &elem, stdin);

		tokenized = tokens(&str);


		if (num == 1)
		{
			tokenized[0] = "";
		}

		i = execute(tokenized);

		free(str);
	}

	while (i && num != -1);

	return (0);
}