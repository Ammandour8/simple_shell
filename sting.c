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
