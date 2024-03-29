#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 *main - entry point
 *@status: integer
 *@env: variable
 *Return: 0
 */
int main(int status, char **env)
{
	char *input = "cisfun$ ", *buffer = NULL;
	char *my_arg[11], *delim = " \n";
	size_t maxsize = 0;
	ssize_t chars;
	pid_t my_pid;
	int i, j;

	while (1)
	{
		if (isatty(0))
			_string(input);
		chars = getline(&buffer, &maxsize, stdin);
		if (chars == -1)
		{
			free(buffer);
			exit(0); }
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = 0;
			i++; }
		j = 0;
		my_arg[j] = strtok(buffer, delim);
		while (my_arg[j])
			my_arg[++j] = strtok(NULL, delim);
		my_arg[j] = NULL;
		my_pid = fork();
		if (my_pid < 0)
		{
			_string("failed");
			free(buffer);
			exit(0); }
		else if (my_pid == 0)
		{
			if (execve(my_arg[0], my_arg, env) == -1)
				continue; }
		else
			wait(&status); }
	free(buffer);
	return (0); }
