#include "commands.h"
#include "memory.h"
#include "general.h"

/**
 * execute - Execute a command in a separate process.
 *
 * @command: Command to be executed.
 * @arguments: Arguments associated with the @command.
 * @info: Additional arguments passed to the program.
 * @buff: Additional argument passed to the program.
 *
 * Return: No explicit return value (void).
 **/

void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}

/**
 * current_directory - Execute the necessary operations for another command.
 *
 * @cmd: Variable representing the command.
 * @arguments: Arguments associated with the @cmd.
 * @buff: Additional argument passed to the program.
 * @info: Additional argument passed to the program.
 *
 * Return: Result of the operation.
 **/

int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}
