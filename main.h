#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PROMPT "$ "
#define MAX_ARGS 32

extern char **environ;
int findCommand(int shellStatus, char *userInput);
char *searchCommand(char *commandName);
int executeCommand(char **commandArgs, int shellStatus);
void exitShell(char **commandArgs, char *userInput, int shellStatus);
int printEnv(int shellStatus);

#endif
