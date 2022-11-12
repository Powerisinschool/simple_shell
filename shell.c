#include "shell.h"

/**
* main - Entry point
* @argc: argument count
* @argv: arguments as array
* Return: Always 0
*/

int main(int argc, char *argv[], char **envp)
{
	char cmd[MAX_TERM_LEN];
	char command[MAX_TERM_LEN];
	char *args[128];
	char **env;
	int err;
	char epath[1024];

	(void) argv;
	(void) argc;

	printf("\nWelcome to simple shell designed by:\n\t-Tolulope Olagunju\n\t-Oyewale Adeosun\n\n");

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
			/* Necessary to avoid segmentation fault! */
			for (env = envp; *env != 0; env++)
			{
				char *thisEnv = *env;
				printf("%s\n", thisEnv);    
			}
			continue;
		}

		parse(command, args);
		/*printf(command);
		printf("\n%s", args[0]);
		printf("\na:%s\n", args[1]);
		printf("\nb:%s\n", args[2]);
		printf("\nc:%s\n", args[3]);
		printf("\nd:%s\n", args[4]);
		printf("\ne:%s\n", args[5]);*/

		(void) epath;

		/* Do not remove this line! */
		/* I don't know why it works like this, but it does! */
		strcpy(epath, args[0]);

		if (!_isCommand(epath))
		{
			printf(NOT_FOUND);
			continue;
		}

		if (_exec(epath, args))
			printf(NOT_FOUND);
	}
	printf("exit\n");
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
