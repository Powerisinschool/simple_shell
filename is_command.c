#include <dirent.h>
#include "shell.h"

void splitpath(char *path, char **paths);

/**
 * _isCommand - Check if command exists on the user's path
 * @cmd: command to check
 * Return: 0 if not exist and vice vera
*/

int _isCommand(char *cmd)
{
	DIR *d;
	struct dirent *dir;
	char PATH[5000];
	char PATHX[5000];
	char ret[500];
	char *paths[5000];
	int k = 0;

	strcpy(PATH, getenv("PATH"));
	strcpy(PATHX, PATH);

	if (cmd[0] == '/' || cmd[0] == '.')
		return (1);

	splitpath(PATHX, paths);

	for (; k < 5000; k++)
	{
		if (paths[k] == NULL)
			break;
		d = opendir(paths[k]);
		if (d)
		{
			while ((dir = readdir(d)) != NULL)
			{
				if (!strcmp(cmd, dir->d_name))
				{
					strcpy(ret, paths[k]);
					strcat(ret, "/");
					strcat(ret, dir->d_name);
					strcpy(cmd, ret);
					return (1);
				}
			}
			closedir(d);
		}
	}

	return (0);
}

/**
 * splitpath - Split the PATH string into individual paths
 * @path: Path string
 * @paths: outpus of split operation
*/

void splitpath(char *path, char **paths)
{
	char *tok = strtok(path, ":");
	int i = 0;

	while (tok)
	{
		paths[i++] = tok;
		tok = strtok(NULL, ":");
	}
	paths[i] = NULL;
}
