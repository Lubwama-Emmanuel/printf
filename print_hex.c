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
	int input, i, isneg, count, digit_1;
	char *hexa, *bin;

	input = va_arg(arguments, int);
	isneg = 0;
	if (input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = binary_array(bin, input, isneg, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = hex_array(bin, hexa, 0, 8);
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
