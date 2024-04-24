#include "main.h"

/**
 * searchCommand - Searches for a command in the directories listed in PATH
 * @commandName: the name of the command to search for
 *
 * Return: the full path of the command if found, NULL otherwise
 */

char *searchCommand(char *commandName)
{
	char *fullPath = NULL;
	char *path, *directory, *pathCopy;
	char delimiter[] = {':', '\n'};

	if (access(commandName, F_OK | X_OK) == 0)
		return (commandName);

	path = getenv("PATH");
	pathCopy = strdup(path);
	directory = strtok(pathCopy, delimiter);

	while (directory != NULL)
	{
		fullPath = malloc(strlen(directory) + strlen(commandName) + 2);
		if (fullPath == NULL)
		{
			free(pathCopy);
			return (NULL);
		}
		sprintf(fullPath, "%s/%s", directory, commandName);
		if (access(fullPath, F_OK | X_OK) == 0)
		{
			free(pathCopy);
			return (fullPath);
		}
		free(fullPath);
		directory = strtok(NULL, delimiter);
	}
	fprintf(stderr, "./hsh: No such file or directory\n");
	free(pathCopy);
	return (NULL);
}
