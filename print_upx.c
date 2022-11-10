#include "main.h"

/**
 * print_upx - prints a decimal in hexadecimal
 * @arguments: character to print
 * @buf: beuffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed.
 */
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, i, isneg, count, dig;
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
	hexa = hex_array(bin, hexa, 1, 8);
	for (dig = i = count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && dig == 0)
			dig = 1;
		if (dig)
		{
			ibuf = handl_buf(buf, hexa[i], ibuf);
			count++;
		}
	}
	free(bin);
	free(hexa);
	return (count);
}
