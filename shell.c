#include "shell.h"

/**
* main - Entry point
* @argc: argument count
* @argv: arguments as array
* Return: Always 0
*/

int main(int argc, char *argv[])
{
	char cmd[MAX_TERM_LEN];
	char command[MAX_TERM_LEN];
	char *args[10];
	int err;

	(void) argv;
	(void) argc;

	while (1)
	{
		err = prompt(cmd);
		if (err)
			break;
		if (cmd[0] == '\n')
			continue;
		stripln(cmd, command);
		_splitstr(command, args);

		if (_exec(command, args))
			printf(NOT_FOUND);
	}

	putchar('\n');
	return (0);
}

/**
* _splitstr - Split string function
* @str: string to be split
* @args: split string to return
*/

void _splitstr(char *str, char **args)
{
	int i = 0;
	char *token = strtok(str, " ");

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}

/**
* prompt - Prompt for input in the shell
* @str: pointer to prompted output
* Return: 0 for success and vice-versa
*/

int prompt(char *str)
{
	printf(GRN "(simple_shell) " CYN "$ " RESET);
	if (fgets(str, MAX_TERM_LEN, stdin) == NULL)
		return (-1);
	return (0);
}

/**
* stripln - Strips strings to their first line break
* @str: string to be stripped of line break
* @command: stripped string
*/

void stripln(char *str, char *command)
{
	size_t i = 0;

	memset(command, 0, strlen(command));
	for (; i < strlen(str) - 1; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		else
			command[i] = str[i];
	}
}
