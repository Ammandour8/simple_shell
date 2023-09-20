#include "shell.h"

/**
 *main - entry point
 *
 *Return: 0
 */
int main(void)
{
	size_t maxsize = 0;
	char *buffer = NULL;

	_string("cisfun$ ");
	getline(&buffer, &maxsize, stdin);
	_string(buffer);

	free(buff);

	return (0);
}
