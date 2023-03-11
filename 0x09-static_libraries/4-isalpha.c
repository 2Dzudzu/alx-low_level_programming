#include "main.h"

/**
 * _isalpha - Entry point
 * @c: the integer value it receives
 * Description: checks if alphabet
 * Return: 1 if true. 0 if false
 */
int _isalpha(int c)
{

	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
