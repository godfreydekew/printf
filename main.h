#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct get_func - Structure of format specifiers and functions toprint it.
 *
 * @fmt: The format specifier.
 * @f: The function T=that prints it.
 */
struct get_func
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int);
};

typedef struct get_func fmt_t;

int _printf(const char *format, ...);

int handle_specifier(const char *, va_list,
		int *, char [], int, int, int, int);


int print_char(va_list, char[], int, int, int, int);
int print_string(va_list, char[], int, int, int, int);
int print_percent(va_list, char[], int, int, int, int);

int print_int(va_list, char[], int, int, int, int);
int print_binary(va_list, char[], int, int, int, int);
int print_unsigned(va_list, char[], int, int, int, int);
int print_octal(va_list, char[], int, int, int, int);
int print_hexadecimal(va_list, char[], int, int, int, int);
int print_hexa_upper(va_list, char[], int, int, int, int);

int print_hexa(va_list, char[], char[], int, char, int, int, int);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
