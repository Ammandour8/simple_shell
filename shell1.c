#include "shell.h"

/**
 *store - prints location
 *@path: character
 *@my_arg: argument
 *Return: 0
 */
char *store(char *path, char *my_arg)
{
	char *pathway, *pathtok, *filename;
	char *delim = ":";

	pathway = strdup(path);
	pathtok = strtok(pathway, delim);
	filename = malloc(strlen(my_arg) + strlen(pathtok) + 2);
	while (pathtok != NULL)
	{
		strcpy(filename, pathtok);
		strcat(filename, "/");
		strcat(filename, my_arg);
		strcat(filename, "\0");
		if (access(filename, X_OK) == 0)
		{
			free(pathway);
			return (filename);
		}
		pathtok = strtok(NULL, delim);
	}
	free(filename);
	free(pathway);
	return (0);
}
/**
 *_getpath - prints path
 *@my_arg: argument
 *Return: 0
 */
char *_getpath(char *my_arg)
{
	char *path;

	path = getenv("PATH");
	if (path)
	{
		path = store(path, my_arg);
		return (path);
	}
	return (0);
}
