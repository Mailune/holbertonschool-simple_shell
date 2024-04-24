#include "main.h"

/**
 * executeCommand - Execute a command using fork and execve
 * @commandArgs: The array of strings representing the command and its arguments
 * @shellStatus: The current status of the shell
 *
 * Return: The updated status of the shell after executing the command
 */

int executeCommand(char **commandArgs, int shellStatus)
{
	pid_t childProcess;

	childProcess = fork();
	if (childProcess < 0)
	{
		perror("Could not create child process");
		exit(EXIT_FAILURE);
	}
	else if (childProcess == 0)
	{
		if (execve(commandArgs[0], commandArgs, NULL) == -1)
		{
			perror("Command could not execute");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&shellStatus);
		shellStatus = WEXITSTATUS(shellStatus);
	}
	return (shellStatus);
}
