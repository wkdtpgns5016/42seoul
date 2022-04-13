#include "libft/libft.h"
#include "ft_printf.h"

char    *flag_zero(int len, char **str)
{
    char    *zero;
    char    *new;

    zero = (char *)malloc(len + 1);
    if (zero == 0)
    {
        free(*str);
        return (0);
    }
    ft_memset(zero, '0', len);
    zero[len] = '\0';
    new = ft_strjoin(zero, *str);
    free(zero);
    free(str);
    if (new == 0)
        return (0);
    return (new);
}

char    *flag_dash(int len, char **str)
{
    char    *dash;
    char    *new;

    dash = (char *)malloc(len + 1);
    if (dash == 0)
    {
        free(*str);
        return (0);
    }
    ft_memset(dash, ' ', len);
    dash[len] = '\0';
    new = ft_strjoin(*str, dash);
    free(dash);
    free(str);
    if (new == 0)
        return (0);
    return (new);
}
