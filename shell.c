#include "simple_shell.h"

/**
 * main - main shell function
 * @ac: int number of variable
 * @av: input variable
 * @environ: environment variable
 *
 * Return: 0 success
 */

int main(int ac __attribute__((unused)), char **av, char **environ)
{
	while (*av && *environ)
	{
		printf("%s\n%s\n", *av, *environ);
		av++;
		environ++;
	}

	return (0);
}
