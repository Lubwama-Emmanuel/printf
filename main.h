#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_us(va_list arguments, char *buf, unsigned int ibuf);
int print_addr(va_list arguments, char *buf, unsigned int ibuf);
int print_rv(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
int print_ctb(va_list arguments, char *buf, unsigned int ibuf);
char *binary_array(char *bin, long int input, int isneg, int limit);
char *oct_array(char *bin, char *oct);
char *short_oct_array(char *bin, char *oct);
char *long_oct_array(char *bin, char *oct);
char *hex_array(char *bin, char *hex, int isupp, int limit);
#endif
