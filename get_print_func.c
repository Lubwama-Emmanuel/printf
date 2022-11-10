#include "main.h"
/**
 * get_print_func - selects function to perform.
 * @s: argument identifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", print_chr}, {"u", print_unt},
		{"s", print_str}, {"o", print_oct},
		{"%", print_prg}, {"x", print_hex},
		{"b", print_ctb}, {"X", print_upx},
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
	return (pr[i].f);
}
