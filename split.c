#include "shell.h"
#include <sys/types.h>

/**
* parse - Split string function
* @line: string to be split
* @argv: split string to return
*/

void parse(char *line, char **argv)
{
	int pass = 0;

	while (*line != '\0')       /* if not the end of line ....... */ 
	{
		if (*line == ' ' || *line == '\t' || *line == '\n' || *line == '"')
		{
			if (*line == '"')
				pass = not(pass);
			*line++ = '\0';     /* replace white spaces with 0    */
		}
		if (line)
			*argv++ = line;          /* save the argument position     */
		while (*line != '\0' && (*line != ' ' || pass) && 
				*line != '\t' && *line != '\n' && *line != '"') 
			line++;             /* skip the argument until ...    */
	}
	*argv = '\0';                 /* mark the end of argument list  */
}

/**
 * not - convert boolean to opposite
 * @boolean: boolean to convert
 * Return: opposite of boolean
*/

int not(int boolean)
{
	if (boolean == 0)
		return (1);
	return (0);
}

/*#include "shell.h"
#include <regex.h>*/

/**
* _splitstr - Split string function
* @str: string to be split
* @args: split string to return
*/

/*void _splitstr(char *str, char **args)
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
}*/
