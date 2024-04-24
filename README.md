<p align="center"> 

<img width="886" alt="Capture d’écran 2024-04-24 à 01 06 36" src="https://github.com/Mailune/holbertonschool-simple_shell/assets/156970898/49412d94-29e3-469b-8a25-db130c5e8147">

## 🔹 Description

#### 👋 Welcome to the Simple Shell README! 

This README serves as guide to understanding and utilizing our Simple Shell, a minimalist program designed to replicate basic Unix shell functionalities.

The Simple Shell is a minimalist command-line interface program designed to replicate basic functionalities of a Unix shell. Composed of several modular files, including main.c, executeCommand.c, exitShell.c, findCommand.c, printEnv.c, and searchCommand.c, the Simple Shell offers users a straightforward platform to interact with their operating system through command inputs.

So, let's dive in and explore our Simple Shell together!

## 🔹 ‼️ Requirements ‼️:

 - Your shell will be compiled this way:
#gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)


## 🔹  Versions
```
This code has been compiled and tested on MacOs 14.4.1 and Ubuntu 23.10
```

## 🔹 Prototypes:

- extern char **environ;
- int findCommand(int shellStatus, char *userInput);
- char *searchCommand(char *commandName);
- int executeCommand(char **commandArgs, int shellStatus);
- void exitShell(char **commandArgs, char *userInput, int shellStatus);
- int printEnv(int shellStatus);

## 🔹 Testing : 

Shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## 🔹 Our examples of tests :

###  ➡ Interactive : 
| COMMAND | OUTPUT |
| --------| -------|
| ls |AUTHORS exitShell.c main.c printEnv.c README.md findCommand.c         main.h searchCommand.c executeCommand.c hsh man_simple_shell |
| ls -l |total 152 -rw-r--r--@ 1 mai  staff    147 Apr 24 22:36 AUTHORS -rw-r--r--@ 1 mai  staff     24 Apr 16 14:10 README.md -rw-r--r--@ 1 mai  staff 753 Apr 24 22:36 executeCommand.c -rw-r--r--@ 1 mai  staff    605 Apr 24 22:36 exitShell.c -rw-r--r--@ 1 mai  staff   1152 Apr 24 22:36 findCommand.c -rwxr-xr-x@ 1 mai  staff  34768 Apr 24 22:37 hsh -rw-r--r--@ 1 mai  staff    622 Apr 24 22:36 main.c -rw-r--r--@ 1 mai  staff    496 Apr 24 22:36 main.h -rw-r--r--@ 1 mai  staff   2640 Apr 24 22:36 man_simple_shell -rw-r--r--@ 1 mai staff    455 Apr 24 22:36 printEnv.c -rw-r--r--@ 1 mai  staff    985 Apr 24 22:36 searchCommand.c |
|pwd | /Users/mai/holbertonschool-simple_shell|
| ls -l /tmp | lrwxr-xr-x@ 1 root  wheel  11 Mar 21 07:13 /tmp -> private/tmp|
|exit | disappearance of "$" exit from our shell|
| ctrl + d | disappearance of "$" exit from our shell |

### ➡ Non interactive :

| COMMAND | OUTPUT |
| --------| -------|
| echo "/bin/ls" \| ./hsh |/bin/ls | ./hsh  |

## 🔹 UML ACTIVITY DIAGRAM 

![uml simple shell](https://github.com/Mailune/holbertonschool-simple_shell/assets/156970898/d55b73c1-d1aa-47f4-8b0e-0e77a6ba1975)

## 🔹 FILES 📔

| FILENAME | DESCRIPTION |
| -------- | ----------- |
| main.h | header file |
| executeCommand.c | Executes a command using fork and execve, updating the shell's status after execution  |
| exitShell.c |Exits the shell with the given exit status, handling optional exit status provided by the user  |
| findCommand.c |: Searches for a command and executes it, including built-in commands like 'exit' and 'env'  |
| printEnv.c |Prints the environment variables to standard output, returning the exit status provided as input | 
| searchCommand.c |Searches for a command in the directories listed in PATH, returning the full path of the command if found, otherwise NULL  |
| main.c | Entry point, user input handling, command execution, error managemen |
|man_simple_shell|man page|


## 🔹 Authors:

#### 👤  Catherine Jiguet
- Github: [@Jiguet-C](https://github.com/Jiguet-C)
- mail: 8685@holbertonstudents.com

#### 👤 Maïlys Rosereau
- Github: [@Mailune](https://github.com/Mailune)
- mail: 8831@holbertonstudents.com
 

Copyright (c) 2024 **Catherine Jiguet & Maïlys Rosereau**
