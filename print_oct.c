#include "main.h"

/**
 * print_oct - prints decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_oct(va_list arguments, char *buf, unsigned int ibuf)
{
	int input, i, isneg, count, dig;
	char *oct, *bin;

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
	bin = fill_binary_array(bin, input, isneg, 32);
	oct = malloc(sizeof(char) * (11 + 1));
	oct = fill_oct_array(bin, oct);
	for (dig = i = count = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && dig == 0)
			dig = 1;
		if (dig)
		{
			ibuf = handl_buf(buf, oct[i], ibuf);
			count++;
		}
	}
	free(bin);
	free(oct);
	return (count);
}
