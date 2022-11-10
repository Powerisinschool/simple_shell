#include "shell.h"
#include <sys/wait.h>

/**
 * _exec - Executor for commands
 * @command: The command to execute
 * @args: The argument count
 * Return: 0 for success and 1 for failed operation
 */

int _exec(char *command, char *args[])
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid)
	{
		/* Very important to ensure loop does not continue during execution */
		waitpid(childpid, &status, 0);
		/*now we know execve is finished*/
	}

	if (childpid == 0)
	{
		execve(command, args, __environ);
		return (1);
	}
	return (0);
}
