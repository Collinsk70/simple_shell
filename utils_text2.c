#include "general.h"
#include "text.h"

/**
 * digits - Count the number of digits in an integer.
 *
 * @n: The number.
 *
 * Return: This function returns the count of digits.
 **/

int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string - Convert the given number to a string.
 *
 * @number: The number to convert.
 *
 * Return: This function returns the number as a string.
 **/

char *to_string(int number)
{
	int n_dgts, i;
	char *_num;

	n_dgts = digits(number);
	_num = malloc(n_dgts * sizeof(char) + 2);
	if (number == 0)
	{
		_num[0] = '0';
		_num[1] = '\0';
		return (_num);
	}
	/* Checks for  NULL */

	_num[n_dgts] = '\0';
	for (i = n_dgts - 1; number != 0; number /= 10, i--)
		_num[i] = (number % 10) + '0';

	return (_num);
}


/**
 * is_numerical - Check if a character is a digit.
 *
 * @n: The character to check.
 *
 * Return: If it is a number, return 1; else, return 0.
 */

int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - Transform a string into a numerical value.
 *
 * @s: The string to convert.
 *
 * Return: The function returns the corresponding numerical value.
 */

int _atoi(char *s)
{
	unsigned int numbers, i;
	int sign;

	sign = 1;
	numbers = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			numbers = (s[i] - 48)	+ numbers * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}

	}

	return (numbers * sign);
}

/**
 * contains_letter - Search for non-digits in a string.
 *
 * @s: The string to search.
 *
 * Return: If a non-digit is found, return _TRUE; if not, return _FALSE.
 */

int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
