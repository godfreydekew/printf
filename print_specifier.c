#include "main.h"
#include <string.h>
/**
 * handle_specifier - Handles format specifiers by
 *			printing an argument based on the type.
 * @fmt: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @index: The index in the @fmt that the specifier is located.
 * @buffer: Buffer array
 * @flags: Active flags
 * @width: Width.
 * @precision: Precision
 * @size: Size
 * Return: The total characters printed or -1 if there is an error.
 */
int handle_specifier(const char *fmt, va_list args,
		int *index, char buffer[], int flags, int width, int precision, int size)
{
	int i, len = 0;
	fmt_t fmt_specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal}, {'x', print_hexa_upper},
		{'p', print_pointer}, {'s', print_non_printable},
		{'r', print_reverse}, {'r', print_rot13string},
		{'%', print_percent}, {'\0', NULL}
	};

	for (i = 0; fmt_specifiers[i].fmt != '\0'; i++)
		if (fmt[*index] == fmt_specifiers[i].fmt)
			return (fmt_specifiers[i].f(args, buffer, flags, width, precision, size));

	if (fmt_specifiers[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &fmt[*index], 1);
		return (len);
	}
	return (-1);
}
