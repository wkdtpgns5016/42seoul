#include "libft/libft.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

int print_c(t_format *format, char c)
{
    int width;
    int len;
    int temp;

    width = format->width;
    len = 0;
    ft_putchar_fd(c, 1);
    len++;
    temp = 0;
    while (width > len)
    {
        ft_putchar_fd(' ', 1);
        width--;
        temp++;
    }
    return (len + temp);
}

int print_s(t_format *format, char *str)
{
    int width;
    int len;
    int temp;

    len = 0;
    width = format->width;
    ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    temp = 0;
    while (width > len)
    {
        ft_putchar_fd(' ', 1);
        width--;
        temp++;
    }
    return (len + temp);
}

void    print_hex(unsigned long long num, int *len)
{
    if (num != 0)
    {
        *len = *len + 1;
        print_hex(num / 16, len);
        if (num % 16 < 10)
            ft_putnbr_fd((int)(num % 16), 1);
        else
            ft_putchar_fd((int)(num % 16) + 87, 1);
    }
}

int print_p(t_format *format, void *ptr)
{
    int width;
    int len;
    int temp;
    unsigned long long addr;

    addr = (unsigned long long)ptr;
    width = format->width;
    len = 2;
    ft_putstr_fd("0x", 1);
    print_hex(addr, &len);
    temp = 0;
    while (width > len)
    {
        ft_putchar_fd(' ', 1);
        width--;
        temp++;
    }
    return (len + temp);
}