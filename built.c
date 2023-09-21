#include "shell.h"
/**
 *built - built in commands
 *@my_arg: argument
 *Return: 0
 */
int built(char **my_arg)
{
	if (strcmp(my_arg[0], "exit") == 0)
	{
		_string("Exiting.... \n");
		exit(0);
	}
	else if (strcmp(my_arg[0], "cd") == 0)
	{
		if (my_arg[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(my_arg[1]);
	}
	return (0);
}
