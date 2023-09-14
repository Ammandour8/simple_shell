#include <stdio.h>
#include <stdlib.h>

/**
 *main - entry point
 *
 *Return: 0
 */
int main(void)
{
	size_t len = 0;
	char *buff = NULL;

	printf("$ ");
	getline(&buff, &len, stdin);
	printf("%s", buff);

	free(buff);

	return (0);
}
