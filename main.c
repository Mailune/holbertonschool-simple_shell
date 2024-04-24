#include "main.h"

/**
 * main - Entry point of the SimpleShell program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(void)
{
	int partIndex, shellStatus = EXIT_SUCCESS;
	char *userInput = NULL;
	size_t inputSize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(PROMPT);
		if (getline(&userInput, &inputSize, stdin) == EOF)
			break;
		for (partIndex = 0; userInput[partIndex] != '\n'; partIndex++)
		{
			if (userInput[partIndex] != ' ')
			{
				shellStatus = findCommand(shellStatus, userInput);
				break;
			}
		}
	}
	if (userInput)
		free(userInput);
	return (shellStatus);
}
