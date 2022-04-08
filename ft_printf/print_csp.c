#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int    print_c(t_format *format, char c)
{
    int width;
    int len;

    width = format->width;
    len = 0;
    ft_putchar_fd(c, 1);
    len++;
    if (width > 1)
    {
        width--;
        while (width)
        {
            ft_putchar_fd(' ', 1);
            len++;
            width--;
        }
    }
    return (len);
}

int print_s(t_format *format, char *str)
{
    int width;
    int len;

    len = 0;
    width = format->width;
    ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    if (width > ft_strlen(str))
    {
        width--;
        while (width)
        {
            ft_putchar_fd(' ', 1);
            width--;
            len++;
        }
    }
    return (len);
}
