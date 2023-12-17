#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



extern char **environ;
/**
 * struct print_fn - Struct print_fn
 *
 * @form: The specifier format
 * @f: The function associated
 */
typedef struct print_fun
{
	char *form;
	int (*f)(va_list args);
} print_fun;
/**
 * struct format_handl - handle format specifiers
 *
 * @spec: The specifier format
 * @f: The function associated
 */
typedef struct format_handl
{
	char *spec;
	int (*f)(va_list *);
} f_handl;
/**
 * struct alias_list - Struct alias_list
 *
 * @name: the name of the alias
 * @value: the value of the alias
 */
typedef struct alias_list
{
	char *name;
	char *value;
} alias_list;
/*string functions*/
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _putchar(char c);
int recursive_int(int n);
int _atoi(char *s);
int _strncmp(char *s1, char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
/*built in functions*/
int _env(void);
int _setenv(char **arg, int count);
int env_manipulation(char *newenv, int i);
int _unsetenv(char **arg, int count);
int _cd(char *path);
int exiting(char *arg, int count);
int echo_dollar(char **arg);
void free_grid(char **grid);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*print error functions*/
int _putchar2(char c);
int recursive_int2(int n);
int _printfint2(va_list args);
int _printfstring2(va_list args);
int _printferror(const char *format, ...);
/*format handle functions*/
int c_hand(va_list *ap);
int s_hand(va_list *ap);
int percent_hand(void);
int i_hand(va_list *ap);
int d_hand(va_list *ap);
typedef int (*func_ptr)(va_list *ap);
int _printf(const char *format, ...);
int spy_cmp(char s1);
int (*get_format(char c))(va_list *ap);
void print_number(int n);
int digit_count(int n);
/*custom functions*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, char *dlm);
int is_dlm(int c, const char *dlm);
/*alias functions*/
int _alias_modify(char **arg, char ***name, char ***value, int s1, int s2);
int print_alias(char *s, char ***name, char ***value);
alias_list *new_alias(char **arg, int s1, int s2);
int _alias(char **arg, int mode);
int alias_cont(char **arg, char ***name, char ***value, int mode);
int alias_sub(char **string, char ***name, char ***value);
char *alias_of_alias(char *cmd, char ***name, char ***value);
/*others functions*/
int execute(char **arg, char *cmd);
void loop(char **prog_name);
char *recieve_input(void);
char **toker(char *str);
int command_runner(char **arg, char *input_string,
		int count, int *error, char **prog_name);
char *checkpoint(char **arg, char *string, int count);
char *_which(char *arg);
int is_builin(char *cmd);
int is_input_eof(void);
char **cmd_list(char **array);
void semicolon_parser(char ***next_ptr);
int error_stat(int code);
int comment_out(char **arg);
void exit_with_code(int err_code, int count, char **arg, char *string);
void print_pwd(void);
char *readfile(FILE *stream);
void file_mode(char **av);


#endif
