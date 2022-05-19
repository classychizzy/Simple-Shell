#include <stdio.h>
#include <string.h>
/**
* main- a function that splits a string
* @string: string to be split
* @delim: basis for splitting the string
* Return: on success split string, else NULL
*/
int main (void)
{
char string[20] = "Hello World";
char *delim = strtok (string, " ");

while (delim != NULL)
{
printf("%s\n", delim);
delim = strtok(NULL, " ");
}
return (0);
}
