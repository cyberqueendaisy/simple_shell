#include "simple_shell.h"

/**
 * print_env - print the environment variable
 * @environ: environment variable
 *
 * Return: 2
 */
int print_env(char **environ)
{
	char **str = environ;
	int len;

	for (len = 0; *str != NULL; str++)
	{
		len = _strlen(*str);

		write(STDOUT_FILENO, *str, len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (2);
}

/**
 * _exit_program - exit the program
 * @environ: environment variable
 *
 * Return: 1
 */
int _exit_program(char **environ)
{
	(void)environ;

	return (1);
}
