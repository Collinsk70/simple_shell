#include "general.h"
#include "text.h"
#include <unistd.h>

/**
 * _putchar_to_fd - Print a character to a specific file descriptor.
 *
 * @c: Char to print.
 * @fd: File descriptor where to print the character.
 *
 * Return: On success, 1.
 *         On error, -1 is returned, and errno is set appropriately.
 **/

int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - Print a string to a specified file descriptor.
 *
 * @msg: String to print in the specified file descriptor.
 * @fd: File descriptor to print.
 *
 * Return: On success, the number of bytes printed.
 *         On error, -1 is returned, and errno is set appropriately.
 **/

int print_to_fd(char *msg, int fd)
{
	int sizes;

	sizes = _strlen(msg);

	return (write(fd, msg, sizes));
}
