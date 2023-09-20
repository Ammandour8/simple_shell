#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int _string(char *str)
{
	int i = 0, count = 0;

	while (str[i])
		count += _putchar(str[i++]);
	return (count);
}

/**
 *main - entry point
 *Return: 0
 */
int main(int i, char **env)
{
	char *input = "cisfun$ ", *buffer = NULL;
	char *my_arg[] = {NULL, NULL};
	size_t maxsize = 0;
	ssize_t chars;
	pid_t my_pid;
	int status;

	while (1)
	{
		_string(input);
		chars = getline(&buffer, &maxsize, stdin);

		if (chars == -1)
		{
			_string("Exit");
			free(buffer);
			exit(0);
		}
		
		i= 0;
		while (buffer[i] == '\n')
			buffer[i] = 0;
		i++;
		my_arg[0] = strdup(buffer);
		my_pid = fork();

		if (my_pid < 0)
		{
			_string("Failed");
			free(buffer);
			exit(0);
		}
		else if (my_pid == 0)
		{
			if (execve(my_arg[0], my_arg, env) == -1)
				_string("command does not exist\n");
		}
		else
			wait(&status);
		_string(buffer);
	}
	free(buffer);
	return (0);
}
