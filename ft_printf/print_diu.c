#include "libft/libft.h"
#include "ft_printf.h"

int add_flag_gsp_d(t_format *format, int value, char **str)
{
    if (ft_strchr(format->flags, ' ') != 0)
        *str = flag_gap(format, str, value);
    else if (ft_strchr(format->flags, '+') != 0)
        *str = flag_plus(format, str, value);
    if (str == 0)
        return (-1);
    return (ft_strlen(*str));
}

int add_flag_zd_d(t_format *format, char **str)
{
    char *temp;
    int len;

    len = ft_strlen(*str);
    if (format->width > len)
    {
        if (ft_strchr(format->flags, '0') != 0)
        {
            if (format->precision == -1)
                *str = flag_zero(format->width - len, str);
        }
        else if (ft_strchr(format->flags, '-') != 0)
            *str = flag_dash(format->width - len, str);
    }
    if (str == 0)
        return (-1);
    return (ft_strlen(*str));
}

char *add_precision_d(t_format *format, int value)
{
    char *num;
    char *zero;
    char *temp;
    int i;

    num = ft_itoa(value);
    if (num == 0)
        return (0);
    if (format->precision - ft_strlen(num) > 1)
    {
        zero = (char *)malloc(format->precision - ft_strlen(num) + 1);
        if (zero == 0)
            return (0);
        i = 0;
        while (i < format->precision - ft_strlen(num))
            zero[i++] = '0';
        zero[i] = '\0';
        temp = ft_strjoin(zero, num);
        free(zero);
        free(num);
        return (temp);
    }
    else
        return (num);
}

int print_width_d(int width, int len)
{
    int size;

    size = 0;
    while (len++ < width)
    {
        ft_putchar_fd(' ', 1);
        size++;
    }
    return (size);
}

int print_d(t_format *format, int value)
{
    int len;
    char *str;

    str = add_precision_d(format, value);
    if (str == 0)
        return (-1);
    if (add_flag_gsp_d(format, value, &str) < 0)
        return (-1);
    if (add_flag_zd_d(format, &str) < 0)
        return (-1);
    len = ft_strlen(str);
    len += print_width_d(format->width, len);
    ft_putstr_fd(str, 1);
    free(str);
    return (len);
}