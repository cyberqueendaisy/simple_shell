#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wchar.h>

extern char **environ;

/**
 * struct data - structure to store data after using getline
 * @line: the string argument
 * @num: the return value of getline
 */
typedef struct data
{
	char *line;
	int num;
} data_t;

/**
 * struct built_in - struct to execute built ins
 * @command: user inputed string command
 * @f_ptr: function pointer
 */
typedef struct built_in
{
	char *command;
	int (*f_ptr)(char **);
} built_ins;

data_t get_inputs(void);
int _exit_program(char **environ);
int print_env(char **environ);
int exec_built_in(char *str, char **env);
int _exec(char **arguments, char **env);
void _fork(char **arguments, char **env);
data_t get_inputs(void);
char *search_path(char **environ);
char *get_all_path(void);
char **get_each_path(void);
char *_which(char *b_command);
char **get_tokens(char *line, char *delimiters);
int _stat(char *argument);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strstr(char *haystack, const char *needle);
char *_strncat(char *dest, char *source, int n);

#endif
