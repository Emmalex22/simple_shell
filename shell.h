#ifndef SHELL_H
#define SHELL_H
/* these are my header files*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#define MAX_COMMAND_LENGTH 250
#define MAX_ARGS 20
extern char **environ;

/*** these are my function prototypes**/
const char *prompt(void);
int ssexecutor(char *usercmd, struct stat *statbuff, char **env);
int mystrlen(const char *s);
char *mystrcat(int n, ...);
char *mystrcpy(char *dest, const char *src, size_t n);
char *check_file_path(const char *filename, struct stat *statbuff);
void free_vec(char **vector, int length);
char *mygetenv(const char *pair);
bool check_file_access(char *filepath, struct stat  *statbuff);
int mystrcmp(const char *s1, const char *s2);
void p_ssenv(void);
char *read_n_parse_input(void);
void handle_path(char *usercmd);
char *check_file_path(const char *filename, struct stat *statbuff);
char *mystrdup(const char *str);
char *handle_built_in(char *usercmd);
void handle_getline_error(ssize_t read);
void handle_fork_error(pid_t baby_pid);
void handle_wait_error(int wstatus);

struct stat statbuff;





#endif
