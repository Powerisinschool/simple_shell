#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments as array
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char str[MAX_TERM_LEN];
	char command[MAX_TERM_LEN];

	(void) argv;
	(void) argc;
	/* printf("%d\n", argc); */
	
	while (1)
	{
		prompt(str);
		if (str[0] == '\n')
			continue;
		stripln(str, command);
		if (_exec(command))
			printf("./shell: No such file or directory\n");

		/* printf("%i\n", err); */
	}

	putchar('\n');
	return (0);
}

void prompt(char *str)
{
	printf(GRN "(simple_shell) " RED "$ " RESET);
	fgets(str, MAX_TERM_LEN, stdin);
}

void stripln(char *str, char *command)
{
	size_t i = 0;

	memset(command,0,strlen(command));
	for (; i < strlen(str)-1; i++)
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