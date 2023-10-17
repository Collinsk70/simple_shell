#include "builtins.h"

/**
 * bin_env - Generate the environment as per the provided arguments.
 *
 * @info: Argument passed in the program.
 * @arguments: Secondary arguments passed in the program.
 **/

void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
