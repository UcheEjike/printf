#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void process_format(const char *format, va_list args, char buffer[], int *buff_ind, int *printed_chars);
void flush_buffer(char buffer[], int *buff_ind);
void int_to_str(int value, char buffer[], int *buff_ind);

#endif /* MAIN_H */
