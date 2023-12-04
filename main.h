#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void process_format(const char *format, va_list args, char buffer[], int *buff_ind, int *printed_chars);
void flush_buffer(char buffer[], int *buff_ind);
void int_to_str(int value, char buffer[], int *buff_ind);
void int_to_base(unsigned int value, char buffer[], int *buff_ind, int base, int uppercase);
void int_to_base_upper(unsigned int value, char buffer[], int *buff_ind, int base);
void handle_u(unsigned int value, char buffer[], int *buff_ind);
void handle_o(unsigned int value, char buffer[], int *buff_ind);
void handle_x(unsigned int value, char buffer[], int *buff_ind);
void handle_X(unsigned int value, char buffer[], int *buff_ind);
void handle_S(char *str, char buffer[], int *buff_ind);

#endif /* MAIN_H */
