#include "simple_shell.h"

/**
 * _putchar - mimicks the sting.h putchar function
 * @c: char input
 *
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - mimicks the stdio.h puts function
 * @str: sting input
 *
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strlen - finds the length of string
 * @str: string input
 *
 * Return: the length of string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{

	}

	return (i);
}

/**
 * _strstr - finds a string in a string
 * @haystack: the parent string to search in
 * @needle: the string being searched for
 *
 * Return: the searched string
 */

char *_strstr(char *haystack, const char *needle)
{
	char *c;

	while (*haystack)
	{
		while (*needle == *haystack)
		{
			needle++, haystack++;
		}
		if (*needle == '\0')
		{
			if (*haystack == '=')
			{
				haystack++;
				c = haystack;
				return (c);
			}
			return (NULL);
		}
		haystack++;
	}
	return (NULL);
}


/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @source: the string to add to dest string
 * @n: integer number of elements to concat
 * Return: string
 */

char *_strncat(char *dest, char *source, int n)
{
	int size = strlen(source) + n + 1;
	char *str = malloc(sizeof(char) * size);

	if (str == NULL)
		return (NULL);

	strcpy(str, dest);
	strncat(str, source, n);

	return (str);
}
