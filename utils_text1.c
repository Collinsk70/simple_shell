#include "text.h"

/**
 * _strlen - Return the length of a string.
 *
 * @msg: String.
 *
 * Return: Returns the length of the string.
 **/

int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenate two strings.
 *
 * @dest: String to be concatenated.
 * @src: Source string.
 *
 * Return: A string resulting from the concatenation.
 */

char *_strcat(char *dest, char *src)
{
	int dest1, i;

	dest1 = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++, dest1++)
		dest[dest1] = src[i];

	dest[dest1] = '\0';

	return (dest);
}

/**
 * _strcpy - Copy a string to another.
 *
 * @dest: Destination for the copy.
 * @src: Source string to be copied.
 *
 * Return: The function returns the value of dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}


/**
 * _strdup - Duplicate a string by allocating new memory.
 *
 * @str: String to be duplicated.
 *
 * Return: Returns a newly allocated copy of the input string.
 **/

char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

/**
 * _strcmp - Compare two strings lexicographically.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Returns an integer value.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}

	return (0);
}
