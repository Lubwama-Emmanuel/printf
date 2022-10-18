#include "main.h"

/**
 * binary_array - outputs binary array.
 * @bin: pointer to bin
 * @input: number to convert
 * @isneg: if input is negative.
 * @limit: size of the bin
 * Return: number of characters.
 */
char *binary_array(char *bin, long int input, int isneg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		bin[i] = '0';
	bin[limit] = '\0';
	for (i = limit - 1; input > 1; i--)
	{
		if (input == 2)
			bin[i] = '0';
		else
			bin[i] = (input % 2) + '0';
		input = input / 2;
	}
	if (input != 0)
		bin[i] = '1';
	if (isneg)
	{
		for (i = 0; bin[i]; i++)
			if (bin[i] == '0')
				bin[i] = '1';
			else
				bin[i] = '0';
	}
	return (bin);
}
