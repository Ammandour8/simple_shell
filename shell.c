#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 *_putchar - prints output
 *@c: character
 *Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_string - prints string
 *@str: string
 *Return: 0
 */
int _string(char *str)
{
	int i = 0, count = 0;

	while (str[i])
		count += _putchar(str[i++]);
	return (count);
}

/**
 *main - entry point
 *@status: integer
 *@env: variable
 *Return: 0
 */
int main(int status, char **env)
{
	char *input = "cisfun$ ", *buffer = NULL;
	char *my_arg[10], *delim = " \n";
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
			exit(0);
		}
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = 0;
			i++;
		}
		j = 0;
		my_arg[j] = strtok(buffer, delim);
		while (my_arg[j])
		{
			my_arg[++j] = strtok(NULL, delim);
		}
		my_arg[j] = NULL;
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
				_string("No such file or directory\n");
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0); }
