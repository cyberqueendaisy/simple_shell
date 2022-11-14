#include "simple_shell.h"

/**
 * get_tokens - splits a string and stores
 * @line: the string to split
 * @delimiters: delimiters
 *
 * Return: array of array
 */

char **get_tokens(char *line, char *delimiters)
{
	char **token;
	char *single_token;

	int position = 0, buffer = 24;

	token = malloc(sizeof(char *) * buffer);

	if (token == NULL)
		exit(EXIT_FAILURE);

	single_token = strtok(line, delimiters);

	while (single_token != NULL)
	{
		token[position] = single_token;
		position++;

		if (position >= buffer)
		{
			buffer = buffer * 2;
			token = realloc(token, sizeof(char *) * buffer);

			if (token == NULL)
			{
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		single_token = strtok(NULL, delimiters);
	}
	token[position] = NULL;

	return (token);
}
