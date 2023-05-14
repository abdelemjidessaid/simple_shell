#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_

/**** MACROS ****/
#define BUF_SIZE 1024

/**** EXTERN VAR ****/
extern char **environ;

/**** HEADER FILES ****/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>


/**** STRUCTS ****/
/**
 * struct format - struct of format that holds the type of data and their
 * functions.
 * @data_type: the type of data.
 * @type: the specific function for the current data.
 *
 * Description: struct format used in print function.
 */
typedef struct format
{
	char *data_type;
	int (*type)();
} frmt;

/**** PROTOTYPES ****/
unsigned int str_len(char *str);
int _strcpy(char *dest, char *src);
void _strcat(char *dest, char *ad);
char *_strdup(char *str);
void _puts(char *str);
int _strcmp(char *one, char *two);
int _strncmp(char *one, char *two, int n);

void free_parser(char *line, char *newline, char **ar, char **array);

void change_dir(char **ar);
int check_prog(char *line, char **ar, char **array, char *newline);
int count_tokens(char *line);
int execute_one(
	char *line, char **ar, char *newline, char **array,
	char **argv, int command_num);
void execute_path(char *p, char **ar);
void line_parser(char *line, int token_num, char *argv[], int command_num);
int find_path(char *p, char **ar);
int find_file(char **ar);



#endif /* _HEADER_FILE_H_ */
