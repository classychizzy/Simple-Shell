#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

/**
* main- function that looks for files in the current directory
* Return: 0 on success
*/
int main(void)
{
	struct dirent *entry; /* pointer to entry made*/
	int files = 0;
	DIR *dr = opendir(".");/* DIR dr is pointer to the directory*/

	if (dr == NULL)
	{
		printf("could not open current directory \n");
		return (1);
	}

	while ((entry = readdir(dr)) != NULL)
	{
		printf("File %3d: %s\n", files, entry->d_name);
	}
	closedir(dr);
	return(0);
}
