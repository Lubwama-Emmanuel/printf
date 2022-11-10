#include "main.h"

/**
 * print_hex - prints a decimal in hexadecimal.
 * @arguments: input string.
 * @buf:buffer pointer
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed
 */
int print_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isneg, count, digit_1;
	char *hexa, *bin;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_intput == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_array(bin, int_input, isneg, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = fill_hex_array(bin, hexa, 0, 8);
	for (digit_1 = i = count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && digit_1 == 0)
			digit_1 = 1;
		if (digit_1)
		{
			ibuf = handl_buf(buf, hexa[i], ibuf);
			count++;
		}
	}
	free(bin);
	free(hexa);
	return (count);
}
