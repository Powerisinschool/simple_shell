#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments as array
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	
	(void)argv;
	(void)argc;

	signal(SIGINT, controlC);
	prompt();
	return (0);
	return (0);
}
