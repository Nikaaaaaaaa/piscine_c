#include "tinyprintf.h"

// affiche un char
static int out_char(int c)
{
    putchar(c);
    return 1;
}

// affiche un str
static int out_str(const char *s)
{
    int n = 0;
    if (!s)
        s = "(null)";
    while (*s)
    {
        putchar(*s);
        ++s;
        ++n;
    }
    return n;
}

// affiche un unsigned int dans la base
static int out_uint_base(unsigned int v, unsigned int base)
{
    char buffer[32];
    const char *digits = "0123456789abcdef";
    int i = 0;
    int n = 0;

    if (base < 2)
        return 0;

    if (v == 0)
        return out_char('0');

    while (v != 0)
    {
        buffer[i++] = digits[v % base];
        v /= base;
    }

    while (i--)
        n += out_char(buffer[i]);
    return n;
}

// affiche un signed int base 10
static int out_int(int x)
{
    char buffer[32];
    int i = 0;
    int n = 0;

    if (x == 0)
        return out_char('0');

    if (x < 0)
        n += out_char('-');

    while (x != 0)
    {
        int d = x % 10;
        if (d < 0)
            d = -d;
        buffer[i++] = '0' + d;
        x /= 10;
    }

    while (i--)
        n += out_char(buffer[i]);

    return n;
}

// gere les differents formats
static int handle_format(va_list *ap, char specifier)
{
    switch (specifier)
    {
    case '%':
        return out_char('%');
    case 'd':
        return out_int(va_arg(*ap, int));
    case 'u':
        return out_uint_base(va_arg(*ap, unsigned int), 10);
    case 's':
        return out_str(va_arg(*ap, const char *));
    case 'c':
        return out_char(va_arg(*ap, int));
    default:
        return out_char('%') + out_char(specifier);
    }
}

// fonction principale printf
int tinyprintf(const char *format, ...)
{
    va_list ap;
    int count = 0;

    if (!format)
        return 0;

    va_start(ap, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
            {
                count += out_char('%');
                break;
            }
            count += handle_format(&ap, *format);
        }
        else
        {
            count += out_char(*format);
        }
        format++;
    }

    va_end(ap);
    return count;
}
