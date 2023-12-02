#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void flush_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
