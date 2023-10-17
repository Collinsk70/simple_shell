#include "general.h"
#include "main.h"
#include "text.h"

/**
 * start - Handle the mode of the shell.
 *
 * Description: The mode can be INTERACTIVE or NON_INTERACTIVE.
 *
 * @info: Structure containing information about the shell.
 **/

void start(general_t *info)
{
	start_prompt(info);
}
