#include "main.h"

/**
 * printEnv - Prints the environment variables to standard output
 * @shellStatus: exit status be returned after printing environment variables
 *
 * Return: the exit status provided as input
 */

int printEnv(int shellStatus)
{
	int envVarIndex;

	for (envVarIndex = 0; environ[envVarIndex] != NULL; envVarIndex++)
	{
		write(1, environ[envVarIndex], strlen(environ[envVarIndex]));
		write(1, "\n", 1);
	}
	return (shellStatus);
}
