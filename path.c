#include "simple_shell.h"

/**
 * search_path - searches the environ variable to get path
 * @environ: environment variable
 *
 * Return: the path
 */

char *search_path(char **environ)
{
	char **str = environ;
	char *search = NULL;

	for (; *str != NULL; str++)
	{
		if (_strstr(*str, "PATH") != NULL)
		{
			search = _strstr(*str, "PATH");
			break;
		}
	}
	return (search);
}

/**
 * get_all_path - get only the path string excluding "path"
 *
 * Return: string
 */

char *get_all_path()
{
	char *search = search_path(environ);
	char *my_token = get_tokens(search, "=")[1];

	return (my_token);
}

/**
 * get_each_path - split all the path variable
 *
 * Return: array of array
 */

char **get_each_path()
{
	char **token = get_tokens(get_all_path(), ":");

	return (token);
}

/**
 * _which - find the exact file location of the command
 * @b_command: the command to search for
 *
 * Return: command path
 */

char *_which(char *b_command)
{
	char *merger, *command;

	char **my_token = get_each_path();

	command = _strncat("/", b_command, _strlen(b_command));

	while (*my_token != NULL)
	{
		merger = _strncat(*my_token, command, strlen(command));
		if (access(merger, F_OK) == 0)
			return (merger);

		my_token++;
	}

	free(my_token);
	return (NULL);
}
