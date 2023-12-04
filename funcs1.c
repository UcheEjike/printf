#include "main.h"
/******************* A function to handle unsigned Numbers in Octal ******/
/**
 * handle_o - handles unsigned octal conversion
 * @value: value to be converted
 * @buffer: value of buffer
 * @buff_ind: index of buffer
 */

void handle_o(unsigned int value, char buffer[], int *buff_ind)
{
	int_to_base(value, buffer, buff_ind, 8, 0);
}


/************** A function to handle Unsigned Numbers in Hexadecimal******/
/**
 * handle_x - handles unsigned hexadecimal
 * @value: value to be converted
 * @buffer: array of characters in the buffer
 * @buff_ind: index of each array character
 */

void handle_x(unsigned int value, char buffer[], int *buff_ind)
{
	int_to_base(value, buffer, buff_ind, 16, 0);
}

/***************** A function to handle Unsigned Upper Hexadecimal ********/
/**
 * handle_X - handles unsigned hexadecimal in uppercase
 * @value: value to be converted
 * @buffer: value of buffer
 * @buff_ind: index of buffer
 */

void handle_X(unsigned int value, char buffer[], int *buff_ind)
{
	int_to_base_upper(value, buffer, buff_ind, 16);
}

/*************** A function to handle int to base conversion **************/
/**
 * int_to_base - A function to handle int to base conversion
 * @value: value to be converted
 * @buffer: array of the buffer
 * @buff_ind: buffer index
 * @base: base to be converted into
 * @uppercase: checks if its in uppercase
 */

void int_to_base(unsigned int value, char buffer[], int *buff_ind, int base,
int uppercase)
{
	int i = 0;
	int j;
	char digits[] = "0123456789abcdef";

	if (uppercase)
	{
		digits[10] = 'A';
		digits[11] = 'B';
		digits[12] = 'C';
		digits[13] = 'D';
		digits[14] = 'E';
		digits[15] = 'F';
	}

	do {
		int digit = value % base;

		buffer[*buff_ind + i] = digits[digit];
		i++;
	} while (value /= base);

	for (j = 0; j < i / 2; j++)
	{
		char temp = buffer[*buff_ind + j];

		buffer[*buff_ind + j] = buffer[(*buff_ind) + i - j - 1];
		buffer[*buff_ind + i - j - 1] = temp;
	}

	*buff_ind += i;
}
/***************** A function to convert int to base in uppercase *********/
/**
 * int_to_base_upper - converts int to base in uppercase
 * @value: value to be converted
 * @buffer: array of buffer
 * @buff_ind: index of each character in the array
 * @base: the base its converting into
 */

void int_to_base_upper(unsigned int value, char buffer[], int *buff_ind,
int base)
{
	int i = 0;
	int j;
	char digits[] = "0123456789ABCDEF";

	do {
		int digit = value % base;

		buffer[*buff_ind + i] = digits[digit];
		i++;
	} while (value /= base);

	for (j = 0; j < i / 2; j++)
	{
		char temp = buffer[*buff_ind + j];

		buffer[*buff_ind + j] = buffer[*buff_ind + i - j - 1];
		buffer[*buff_ind + i - j - 1] = temp;
	}

	*buff_ind += i;
}
