#include "main.h"

/**
 * oct_array - writes character to stdout
 *
 * @bin: array storing binary.
 * @oct: array storing oct.
 * Return: binary array.
 */
char *oct_array(char *bin, char *oct)
{
	int op, i, j, ioct, limit;

	oct[11] = '\0';
	for (i = 31, ioct = 10; i >= 0; i--, ioct--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bin[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}
