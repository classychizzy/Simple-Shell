#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* main - a function that prints a character
* @size: number of bytes allocated to string
* @string:pointer to the string entered 
* @print: variable with the getline
*/
int main(void)
{ 
	size_t size = NULL;
	ssize_t print;
	char *string;

	printf("$");

	string = (char *) malloc (size);
	print = getline(&string, &size, stdin);

	printf("\n");

	if (print < 1)
	{
		puts("couldn't read input");
		free (string);
		return (-1);
	}

	printf ("current size of string is :%ld\n" , print);
	free(string);
	return (0);
}
