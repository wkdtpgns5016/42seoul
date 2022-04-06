#include "ft_print.h"
#include "libft/libft.h"

int is_vaild_format(t_format *format)
{

}

int check_flag_to_type(t_format *format)
{
    if (format->type == 'c' || format->type == 's' || format->type == 'p')
    {
        return (check_include_flag(format->flags, "-"));
    }
    else if (format->type == 'd' || format->type == 'i')
    {
        return (check_include_flag(format->flags, "-0 +"));
    }
    else if (format->type == 'u')
    {
        return (check_include_flag(format->flags, "-0"));
    }
    else if (format->type == 'x' || format->type == 'X')
    {
        return (check_include_flag(format->flags, "-0#"));
    }
    else
    {
        return (check_include_flag(format->flags, ""));
    }
}

int check_include_flag(char *flags, char *check)
{
    while (*flags != 0)
    {
        if (ft_strchr(check, *flags) == 0)
            return (0);
        flag++;
    }
    return (1);
}