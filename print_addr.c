#include "main.h"

/**
 * print_addr - prints address of an input variable.
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf:index for buffer.
 * Return: number of chars printed.
 */
int print_addr(va_list arguments, char *buf, unsigned int ibuf)
{
	void *add;
	long int input;
	int i, count, m, isneg;
	char *hex, *bin;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (5);
	}
	input = (intptr_t)add;
	isneg = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = binary_array(bin, input, isneg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = hex_array(bin, hex, 0, 16);
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);
	for (m = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && m == 0)
			m = 1;
		if (m)
		{
			ibuf = handl_buf(buf, hex[i], ibuf);
			count++;
		}
	}
	free(bin);
	free(hex);
	return (count + 2);
}
