#include "main.h"
/********************* A function to handle Unsigned Numbers ************/
/**
 * handle_u - handles unsigned numbers
 * @value: value to check for
 * @buffer: array of the buffer
 * @buff_ind: index of the buffer character
 */
void handle_u(unsigned int value, char buffer[], int *buff_ind)
{
	int_to_str(value, buffer, buff_ind);
}

/*************** A functio to handle custom specifier S ****************/
/**
 * handle_S - Handles custom specifier S
 * @str: string to convet
 * @buffer: array of the buffer
 * @buff_ind: buffer index
 */
void handle_S(char *str, char buffer[], int *buff_ind)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer[*buff_ind] = '\\';
			(*buff_ind)++;
			buffer[*buff_ind] = 'x';
			(*buff_ind)++;
			buffer[*buff_ind] = (str[i] / 16 < 10) ?
			(str[i] / 16 + '0') : (str[i] / 16 - 10 + 'A');
			(*buff_ind)++;
			buffer[*buff_ind] = (str[i] % 16 < 10) ?
			(str[i] % 16 + '0') : (str[i] % 16 - 10 + 'A');
			(*buff_ind)++;
		}

		else
		{
		buffer[*buff_ind] = str[i];
		(*buff_ind)++;
		}

		i++;
	}
	buffer[*buff_ind] = '\0';
}
