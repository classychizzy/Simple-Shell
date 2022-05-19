#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
*  main- a function example of stat
* Return: 0 on success
*/
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf("found\n");
		}
		else
		{
			printf("NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
