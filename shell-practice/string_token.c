#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* main- a function that gets input from user
* and splits the string
* @str: string to be given token
* @delim: character that defines the split
* Return: split string or null
*/
int main (void)
{
ssize_t get_input;
size_t size = NULL;
char *str;

printf("$");

str = (char *) malloc(size);
get_input = getline(&str, &size, stdin);

if (get_input < 1) 
{
	puts("unable to read string");
	free (str);
	return (1);
}

else
{
	char *token = strtok(str, " ");

	while (token != NULL)
	{
	printf("%s\n", token);
	token = strtok(NULL, " ");
	}

printf("current size of string is: %ld\n", get_input);
free (str);
return (0);
}
}
