#include "builtins.h"

/**
 * builtins - Evaluate if the given command is a shell builtin and execute it.
 *
 * @info: Structure holding relevant shell information.
 * @arguments: Arguments provided to the program.
 *
 * Return: Return TRUE if the command is a shell builtin; otherwise, return FALSE.
 **/
int builtins(general_t *info, char **arguments)
{
    int status;

    status = check_builtin(info, arguments);
    if (status == _FALSE)
        return (_FALSE);

    return (_TRUE);
}

/**
 * check_builtin - Examine whether the specified command is a shell builtin and perform its execution.
 *
 * @info: Structure containing vital shell details.
 * @arguments: Arguments passed to the program.
 *
 * Return: Return TRUE if the command is a recognized shell builtin; otherwise, return FALSE.
 **/
int check_builtin(general_t *info, char **arguments)
{
    int i, size;
    builtin_t builtins[] = {
        {"exit", bin_exit},
        {"env", bin_env}
    };

    size = sizeof(builtins) / sizeof(builtins[0]);
    for (i = 0; i < size; i++)
    {
        if (_strcmp(info->command, builtins[i].command) == 0)
        {
            builtins[i].func(info, arguments);
            return (_TRUE);
        }
    }

    return (_FALSE);
}

