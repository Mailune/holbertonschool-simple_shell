#include "main.h"

/**
 * exitShell - Exits the shell with the given exit status
 * @commandArgs: array of strings representing the command and its arguments
 * @userInput: a buffer containing the command entered by the user
 * @shellStatus: the exit status to be returned to the operating system
 *
 * Return: void
 */

void exitShell(char **commandArgs, char *userInput, int shellStatus)
{
	if (commandArgs[1] != NULL && commandArgs[2] != NULL)
		return;

	if (commandArgs[1] != NULL)
	{
		shellStatus = atoi(commandArgs[1]);
		if (shellStatus < 0)
			return;
	}
	free(userInput);
	exit(shellStatus);
}
