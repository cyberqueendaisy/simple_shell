#include "simple_shell.h"

/**
 * _stat - status of a file
 * @argument: path
 *
 * Return: int value
 */

int _stat(char *argument)
{
	struct stat file;

	if (stat(argument, &file) == 0)
		return (0);

	return (1);
}
