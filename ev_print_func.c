#include "main.h"
/**
 * ev_print_func - returns number of identifiers.
 * @s: identifier.
 * @index: index of identifier.
 * Return: number of identifiers.
 */
int ev_print_func(const char *s, int index)
{
	print_t pr[] = {
		{"c", print_chr}, {"o", print_oct},
		{"s", print_str}, {"u", print_unt},
		{"%", print_prg}, {"x", print_hex},
		{"X", print_upx},
		{"b", print_ctb},
		{"S", print_us},
		{"p", print_addr},
		{"r", print_rv},
		{"i", print_int},
		{"d", print_int},
		{"R", print_rot},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}
