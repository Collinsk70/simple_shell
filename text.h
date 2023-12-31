#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "general.h"
#include "memory.h"

/* code for text.c...*/
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* code forutils_text.c.. */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* code forutils_text2.c.. */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* code forprinters.c... */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* code forprinters_out.c... */
int _putchar(char c);
int print(char *msg);

/* code forprinters_err.c.. */
int print_err(char *msg);

/* code fortokenization.c.. */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* code forpatterns.c.. */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

/* code forpatterns_replacer.c... */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif /* TEXT_H */
