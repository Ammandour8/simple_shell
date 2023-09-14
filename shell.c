#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_SIZE 1024
/**
 *main - entry point
 *Return: 0
 */
int main(void)
{
	char input;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (!input)
			printf("Error");
		else if (input == "exit")
			break;
	}
	return (0);
}
