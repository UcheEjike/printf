#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
/**
 * _printf - a simple and custom printf function with limited format specifiers
 * flush_buffer - a function that flushes the buffer when its full
 * @format: The format of the characters
 *
 * Return: Number of characters to be printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFF_SIZE];
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_size)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, list, buffer, flags,
					width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - This is a function that prints the content of the buffer
 * @buffer: Array of characters
 * @buff_ind: index of a particular character to be added
 */

void print_buffer(char buffer[], int *buff_ind);
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
