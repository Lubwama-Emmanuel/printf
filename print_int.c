#include "main.h"

/**
 * print_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */

int print_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int i, tmp, j, div, isneg;

	input = va_arg(arguments, int);
	isneg = 0;
	if (input < 0)
	{
		i = input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		i = input;
	}
	div = 1;
	for (tmp = i; tmp > 9; tmp /= 10)
	{
		div *= 10;
	}
	for (j = 0; div > 0; div /= 10, j++)
	{
		ibuf = handl_buf(buf, ((i / div) % 10) + 48, ibuf);
	}
	return (i + isneg);
}
