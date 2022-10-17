#include "main.h"
#include <stdio.h>
/**
 * print_prg - writes the charater to output.
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: int.
 */
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handl_buf(buf, '%', i);

	return (1);
}
