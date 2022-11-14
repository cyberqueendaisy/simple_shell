#include "simple_shell.h"

/**
 * exec_built_in - check if argument is a built invariable
 * @str: string input argument
 * @env: environment variable
 *
 * Return: 0 (not built_in)
 */

int exec_built_in(char *str, char **env)
{
	int i;

	built_ins my_func[] = {
		{"env", print_env},
		{"exit", _exit_program},
		{NULL, NULL}
	};

	for (i = 0; my_func[i].command != NULL; i++)
	{
		if (strcmp(str, my_func[i].command) == 0)
		{
			return (my_func[i].f_ptr(env));
		}
	}

	return (0);
}

/**
 * _exec - execute the commands
 * @arguments: array of array
 * @env: environment variable
 *
 * Return: 0
 */

int _exec(char **arguments, char **env)
{
	if (execve(arguments[0], arguments, env) == -1)
		perror("Error:");

	return (0);
}
