#include <stdio.h>
/**
* main- prints the environment
* Return: 0 on success
*/
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), 
char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
