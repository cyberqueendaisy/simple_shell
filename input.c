#include "simple_shell.h"

/**
 * get_inputs - get the input arguments from user
 *
 * Return: mydata
 */
data_t get_inputs(void)
{
	size_t n = 0;
	data_t mydata;

	mydata.line = NULL;
	mydata.num = getline(&mydata.line, &n, stdin);

	if (mydata.num == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}

	return (mydata);
}
