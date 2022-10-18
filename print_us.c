#include "main.h"

/**
 * print_us - prints string with values of non-printed chars.
 * @arguments: input string
 * @buf: buffer pointer.
 * @ibuf: index of buffer pointer.
 * Return: number of chars printed.
 */
int print_us(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hex, *bin;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	bin = malloc(sizeof(char) * (32 + 1));
	hex = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handl_buf(buf, '\\', ibuf);
			ibuf = handl_buf(buf, 'x', ibuf);
			op = str[i];
			bin = binary_array(bin, op, 0, 32);
			hex = hex_array(bin, hex, 1, 8);
			ibuf = handl_buf(buf, hex[6], ibuf);
			ibuf = handl_buf(buf, hex[7], ibuf);
			sum = sum + 3;
		}
		else
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	free(bin);
	free(hex);
	return (i + sum);
}
