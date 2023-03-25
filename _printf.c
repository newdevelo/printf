#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int printed = 0;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    printed++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        printed++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    printed++;
                    break;
                }
                default: {
                    // Unknown conversion specifier, ignore it
                    break;
                }
            }
        } else {
            putchar(*format);
            printed++;
        }
        
        format++;
    }
    
    va_end(args);
    
    return printed;
}
