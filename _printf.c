#include "main.h"

void print_buffer(char buffer[], int *index);

/**
 * _printf - Implement the printf function.
 * @format: Constant string format.
 * Return: The number of printed characters.
 */

int _printf(const char *format, ...)
{
	int i, no_printed = 0, count = 0;
	int flags, width, precision, size, index = 0;
	va_list args;
	char buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[index] = format[i];
			index++;

			if (index == BUFF_SIZE)
				print_buffer(buf, &index);
			count++;
		}
		else
		{
			print_buffer(buf, &index);
			size = get_size(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			flags = get_flags(format, &i);
			i += 1;
			no_printed = handle_specifier(format, args, &i, buf, flags, width, precision, size);
			if (no_printed == -1)
				return (-1);
			count += no_printed;
		}
	}

	print_buffer(buf, &index);

	va_end(args);

	return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);

	*index = 0;
}
