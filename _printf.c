#include "main.h"
#include <unistd.h>
/**
 * _printf - a simple and custom printf function with limited format specifiers
 * flush_buffer - a function that flushes the buffer when its full
 * @format: The format of the characters
 *
 * Return: Number of characters to be printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int printed_chars = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return -1;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char ch = va_arg(args, int);
				buffer[buff_ind++] = ch;
				if (buff_ind == BUFF_SIZE)
					flush_buffer(buffer, &buff_ind);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				const char *str = va_arg(args, const char *);
				for (; *str != '\0'; str++)
				{
					buffer[buff_ind++] = *str;
					if (buff_ind == BUFF_SIZE)
						flush_buffer(buffer, &buff_ind);
					printed_chars++;
				}
			}
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
					flush_buffer(buffer, &buff_ind);
				printed_chars++;
			}
		}
		else
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				flush_buffer(buffer, &buff_ind);
			printed_chars++;
		}
	}

	flush_buffer(buffer, &buff_ind);

	va_end(args);

	return printed_chars;
}

void flush_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
