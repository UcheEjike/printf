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
va_list args;
    va_start(args, format);
    
    int count = 0; // Pour compter le nombre de caractères imprimés
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Passer au caractère suivant après '%'
            if (*format == 'c') {
                // Afficher un caractère
                char c = va_arg(args, int); // Récupérer le caractère à afficher
                putchar(c); // Imprimer le caractère sur stdout
                count++;
            } else if (*format == 's') {
                // Afficher une chaîne de caractères
                char *s = va_arg(args, char*); // Récupérer la chaîne à afficher
                while (*s != '\0') {
                    putchar(*s); // Imprimer chaque caractère de la chaîne sur stdout
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Afficher le caractère '%'
                putchar('%'); // Imprimer le caractère '%' sur stdout
                count++;
            }
        } else {
            // Si le caractère n'est pas '%', l'imprimer tel quel
            putchar(*format);
            count++;
        }
        
        format++; // Passer au caractère suivant dans la chaîne de format
    }
    
    va_end(args);
    return count; // Retourner le nombre total de caractères imprimés
}
