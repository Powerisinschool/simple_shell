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
	char *const args[] = {"/bin/sh", "-c", NULL};
	pid_t childpid;

	(void) argv;
	(void) argc;
	/* printf("%d\n", argc); */
	
	while (1)
	{
		prompt(str);
		/* printf("%s\n", str); */
		childpid = fork();

		if(childpid == 0)
		{
			execve(str, args, __environ);
			printf("\n./shell: No such file or directory\n");
		}

		/* printf("%i\n", err); */
	}

	putchar('\n');
	return (0);
}

void prompt(char *str)
{
	printf(GRN "(simple_shell) " RED "$ " RESET);
	scanf("%[^\n]%*c", str);
}