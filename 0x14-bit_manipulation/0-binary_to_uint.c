#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int pos;
	int rue;
	int ken;

	if (!b)
		return (0);
	pos = 0;

	for (rue = 0; b[rue] != '\0'; rue++)
	      ;

	for (rue--, ken = 1; rue >= 0; rue--, ken *= 2)
	{
		if (b[rue] != '0' && b[rue] != '1')
		{
			return (0);
		}

		if (b[rue] & 1)
		{
			pos += ken;
		}
	}

	return (pos);
}
