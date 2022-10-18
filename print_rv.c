#include "main.h"

/**
 * print_rv - prints string in reverse
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer.
 * Return: number of char printed.
 */
int print_rv(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nil[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nil[i]; i++)
			ibuf = handl_buf(buf, nil[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		ibuf = handl_buf(buf, str[j], ibuf);
	}
	return (i);
}
