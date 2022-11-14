#include "simple_shell.h"

/**
 * _fork - fork
 * @arguments: input arguments
 * @env: environment variable
 *
 * Return: void
 */

void _fork(char **arguments, char **env)
{
	pid_t status, child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		_exec(arguments, env);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
