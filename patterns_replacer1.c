#include "general.h"
#include "text.h"
#include "commands.h"

/**
 * replacement - Entry point for the replacement function.
 *
 * @info: Input value.
 * @index: Input value.
 * @string: Input value.
 *
 * Return: The function returns the modified string.
 **/

char *replacement(general_t *info, int *index, char *string)
{
	char *temp;
	char symbl;

	(void) index;

	symbl = *string;
	if (symbl != '?' && symbl != '$')
	{
		temp = replace_env(info, string);
		return (temp);
	}

	temp = (symbl == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (temp);
}

/**
 * replace_env - Entry point function for replacing environment variables.
 *
 * @info: Input value.
 * @environment: Input argument.
 *
 * Return: The function returns the modified string.
 **/


char *replace_env(general_t *info, char *environment)
{
	char *environ;

	(void) info;

	environ = _getenv(environment);
	if (environ != NULL)
		return (environ);

	return (NULL);
}
