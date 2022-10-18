#include "main.h"

/**
 * hex_array - write character to stdout.
 * @bin: array witn binary value.
 * @hex: array with hex value.
 * @isupp: int that determines case of hex array.
 * @limit: size of hex.
 * Return: binary array.
 */
char *hex_array(char *bin, char *hex, int isupp, int limit)
{
	int op, i, j, lett;

	hex[limit] = '\0';
	if (isupp)
		lett = 55;
	else
		lett = 87;
	i = (limit * 4) - 1;

	while (i >= 0)
	{
		for (op = 0; j = 1; j <= 8; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + lett;
		i--;
	}
	return (hex);
}
