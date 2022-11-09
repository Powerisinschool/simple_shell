#include "shell.h"
#include <sys/wait.h>

int _exec(char *command)
{
	char *const args[] = {"/bin/sh", "-c", NULL};
	pid_t childpid;
	int status;

	if ((childpid = fork())) {
        waitpid(childpid, &status, 0);
        /*now we know execve is finished*/
    }

	if(childpid == 0)
	{
		execve(command, args, __environ);
		return (1);
	}
	return (0);
}