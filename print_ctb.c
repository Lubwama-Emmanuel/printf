#include "main.h"

/**
 * output_array - outputs binary array.
 * @bin: pointer to bin
 * @input; number to convert
 * @isneg: if input is negative.
 * @limit: size of the bin
 * Return: number of characters.
 */
char *output_array(char *bin, long int input, int isneg, int limit)
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

/**
 * print_ctb - Converts int to binary.
 * @arguments: arguments.
 * @buf: pointer to buffer.
 * @ibuf: position in buffer.
 * Return: int.
 */
int print_ctb(va_list arguments, char *buf, unsigned int ibuf)
{
	int i, count, j, m, isneg;
	char *bin;

	i = va_arg(arguments, int);
	isneg = 0;
	if (i == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (i < 0)
	{
		i = (i * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = output_array(bin, i, isneg, 32);
	m = 0;
	for (count = j = 0; bin[j]; j++)
	{
		if (m == 0 && bin[j] == '1')
			m = 1;
		if (m == 1)
		{
			ibuf = handl_buf(buf, bin[j], ibuf);
			count++;
		}
	}
	free(bin);
	return (count);
}
