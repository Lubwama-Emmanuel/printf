#include "main.h"

/**
 * print_rot - writes string in rot13.
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointr
 * Return: number of chars printed.
 */
int print_rot(va_list arguments, char *buf, unsigned int ibuf)
{
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nil[] = "(avyy)";

	str = va_arg(arguments, char *);

	if (str == NULL)
	{
		for (i = 0; nil[i]; i++)
			ibuf = handl_buf(buf, nil[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				k = 1;
				ibuf = handl_buf(buf, rot[j], ibuf);
				break;
			}
		}
		if (k == 0)
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	return (i);
}
