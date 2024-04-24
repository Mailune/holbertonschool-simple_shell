#include "main.h"

/**
 * findCommand - Searches for a command and executes it
 * @shellStatus: the status of the shell
 * @userInput: the command entered by the user
 *
 * Return: the updated status of the shell
 */

int findCommand(int shellStatus, char *userInput)
{
	char *commandParts[MAX_ARGS], *currentPart;
	int partIndex, isPathCmd = 0;
	char *command;
	char delimiter[] = {' ', '\n'};

	currentPart = strtok(userInput, delimiter);
	for (partIndex = 0; currentPart != NULL; partIndex++)
	{
		commandParts[partIndex] = currentPart;
		currentPart = strtok(NULL, delimiter);
	}
	commandParts[partIndex] = NULL;

	if (strcmp(commandParts[0], "exit") == 0)
	{
		exitShell(commandParts, userInput, shellStatus);
		return (shellStatus);
	}

	if (strcmp(commandParts[0], "env") == 0)
	{
		printEnv(shellStatus);
		return (shellStatus);
	}

	command = searchCommand(commandParts[0]);
	if (command == NULL)
		return (shellStatus);

	if (strcmp(command, commandParts[0]) != 0)
	{
		commandParts[0] = command;
		isPathCmd = 1;
	}
	shellStatus = executeCommand(commandParts, shellStatus);
	if (isPathCmd)
		free(commandParts[0]);

	return (shellStatus);
}
