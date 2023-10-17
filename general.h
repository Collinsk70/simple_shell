#ifndef GENERAL_H
#define GENERAL_H

#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133

typedef struct __attribute__((__packed__))
{
    int argc;                 /* Number of received arguments */
    char **argv;              /* Received arguments */
    int mode;                 /* INTERACTIVE or NON_INTERACTIVE mode */
    int error_code;           /* Error code for error message handling */
    char *command;            /* Command to be executed */
    int n_commands;           /* Number of executed commands */
    char *value_path;         /* Path of a command */
    int is_current_path;      /* Flag indicating if it is the current path */
    int status_code;          /* Last exit code */
    char *buffer;             /* Line read with the getline function */
    char **arguments;         /* Line split into words */
    char *environment;        /* Last environment variable obtained */
    int pid;                  /* Process ID */
} general_t;

typedef struct __attribute__((__packed__))
{
    char *message;            /* Error message */
    int code;                 /* Error code for identifying the message */
} error_t;

typedef struct __attribute__((__packed__))
{
    char *command;            /* Command name, arguments[0] = cmd */
    void (*func)(general_t *info, char **arguments);  /* Pointer to the command's execution function */
} builtin_t;

#endif

