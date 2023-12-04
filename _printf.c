#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#define BUFF_SIZE 1024

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
	int printed_chars = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	process_format(format, args, buffer, &buff_ind, &printed_chars);
	flush_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed_chars);
}
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int mask = 0;

    int count = 0;

    if (num == 0)
        return (_putchar('0'));

    for (mask = 1 << 31; mask > 0; mask >>= 1)
    {
        if (num & mask)
            count += _putchar('1');
        else
            count += _putchar('0');
    }

    return (count);
}
void process_format(const char *format, va_list args, char buffer[],
		int *buff_ind, int *printed_chars)
{
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
			{
				int value = va_arg(args, int);

				int_to_str(value, buffer, buff_ind);
				(*printed_chars)++;
			}
			else if (format[i] == 'c')
			{
				char ch = va_arg(args, int);

				buffer[(*buff_ind)++] = ch;

				(*printed_chars)++;
			}
			else if (format[i] == 's')
			{
				const char *str = va_arg(args, const char *);

				for (; *str != '\0'; str++)
				{
					buffer[(*buff_ind)++] = *str;
					(*printed_chars)++;
				}
			}
			else if (format[i] == 'p')
			{
				void *ptr = va_arg(args, void *);

				buffer[(*buff_ind)++] = '0';
				buffer[(*buff_ind)++] = 'x';

				int_to_base((uintptr_t)ptr, buffer, buff_ind, 16, 1);
				(*printed_chars) += 2;
			}
			else if (format[i] == '%')
			{
				buffer[(*buff_ind)++] = '%';
				(*printed_chars)++;
			}
			else if (format[i] == 'b')
            		{
             			unsigned int value = va_arg(args, unsigned int);
                		*printed_chars += print_binary(args);
          		}

		else
		{
			buffer[(*buff_ind)++] = format[i];
			if (*buff_ind == BUFF_SIZE)
			{
				flush_buffer(buffer, buff_ind);
				(*printed_chars)++;
			}
		}
	}
}


/***************** A function to flush the buffer ***********************/
void flush_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}


/****************** A function to convert the integers to string *************/

void int_to_str(int value, char buffer[], int *buff_ind)
{
	int i = 0;
	int j;

	if (value < 0)
	{
		buffer[(*buff_ind)++] = '-';
		value = -value;
	}

	do {
		int digit = value % 10;

		buffer[(*buff_ind) + i] = '0' + digit;

		i++;
		value /= 10;
	} while (value > 0);


	for (j = 0; j < i / 2; j++)
	{
		char temp = buffer[(*buff_ind) + j];

		buffer[(*buff_ind) + j] = buffer[(*buff_ind) + i - j - 1];

		buffer[(*buff_ind) + i - j - 1] = temp;
	}

	*buff_ind += i;
}
