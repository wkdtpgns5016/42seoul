#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *temp;
    int     len;

    temp = (char *)s;
    len = ft_strlen(s) + 1;
    while (*temp != 0)
        temp++;
    while (len >= 0)
    {
        if (*temp == (char)c)
            return (temp);
        temp--;
        len--;
    }
    return (0);
}
