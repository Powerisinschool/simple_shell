#include "shell.h"

void sigintHandler(int sig_num);

/**
* main - Entry point
* @argc: argument count
* @argv: arguments as array
* @envp: environmental variables
* Return: Always 0
*/

int main(int argc, char *argv[], char **envp)
{
	char cmd[MAX_TERM_LEN], command[MAX_TERM_LEN], epath[1024];
	char *args[128];
	char **env;
	int err;

	(void) argv;
	(void) argc;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		memset(command, 0, MAX_TERM_LEN);
		err = prompt(cmd);
		if (err)
			break;
		if (cmd[0] == '\n')
			continue;
		stripln(cmd, command);
		if (!strcmp(command, "exit"))
			break;
		if (!strcmp(command, "env"))
		{
			for (env = envp; *env != 0; env++)
			{
				char *thisEnv = *env;

				printf("%s\n", thisEnv);
			}
			continue;
		}
		parse(command, args);
		/* Do not remove this line! */
		strcpy(epath, args[0]);
		if (!_isCommand(epath))
		{
			printf(NOT_FOUND);
			continue;
		}
		if (_exec(epath, args))
			printf(NOT_FOUND);
	}
	return (0);
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

/**
 * sigintHandler - Handle sigint
 * @sig_num: signal number
 */

void sigintHandler(int sig_num)
{
	(void) sig_num;
	printf("\n" GRN "(simple_shell) " CYN "$ " RESET);
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
