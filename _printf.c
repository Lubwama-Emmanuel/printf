#include "main.h"

/**
 * _printf - variadic function that works as printf
 *
 * @format: data to print
 *
 * Return: returns the printed string
 */
int _printf(const char *format, ...)
{
	int j = 0, i = 0;
	char buff[1024], char *s;

	va_list ap, va_start(ap, format);

	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					buff[j] = (char)va_arg(ap, int);
					j++;
					break;
				}
				case 's':
				{
					s = va_arg(ap, char*);
					strcpy(&buff[j], s);
					j += strlen(s);
					break;
				}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		} i++;
	}
	fwrite(buff,  j, 1, stdout);
	va_end(ap), return (hj);
}
