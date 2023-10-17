#include "text.h"

/**
 * split_words - Split a line into words.
 *
 * @line: Line to be split.
 * @sep: Delimiters for splitting the words.
 *
 * Return: The function returns a set of words.
 **/

char **split_words(char *line, const char *sep)
{
	char **words, **temp, *tokens;
	size_t new_sizes, old_sizes;

	old_sizes = sizeof(char *);
	words = malloc(old_sizes);
	if (words != NULL)
	{
		new_sizes = 1;
		tokens = strtok(line, sep);
		while (tokens)
		{
			if (tokens[0] == '#')
				break;
			temp = _realloc(words, old_sizes, (new_sizes + 1) * sizeof(char *));
			old_sizes = (new_sizes + 1) * sizeof(char *);
			if (temp == NULL)
				break;

			words = temp;
			++new_sizes;

			words[new_sizes - 2] = malloc(_strlen(tokens) + 1);
			if (words == NULL)
			{
				free(words);
				free(temp);
			}

			if (words[new_sizes - 2] != NULL)
				_strcpy(words[new_sizes - 2], tokens);

			tokens = strtok(NULL, sep);

			temp = NULL;
		}

		words[new_sizes - 1] = NULL;
	}

	return (words);
}

/**
 * join_words - Join three words with a separator.
 *
 * Description: Result -> w1.sep.w2.sep.nl
 *
 * @word1: The first word to join.
 * @word2: The second word to join.
 * @word3: The third word to join.
 * @sep: Separator between the words.
 *
 * Return: Returns the line composed of three parts followed by a separator and
 * ending with a new line.
 **/

char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *auxil;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *)sep);
	else
		sep = "";

	auxil = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (auxil == NULL)
		return (NULL);

	auxil = _strcpy(auxil, word1);
	auxil = _strcat(auxil, (char *)sep);
	auxil = _strcat(auxil, word2);
	auxil = _strcat(auxil, (char *)sep);
	auxil = _strcat(auxil, word3);
	auxil = _strcat(auxil, "\n");

	return (auxil);
}
