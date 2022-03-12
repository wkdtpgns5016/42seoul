#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *temp;
    int     len;

    temp = (char *)s;
    len = 0;
    while (*temp++ != 0)
        len++;
    while (len >= 0)
    {
        if (*temp == (char)c)
            return (temp);
        temp--;
        len--;
    }
    return (0);
}
