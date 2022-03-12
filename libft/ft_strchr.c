#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    char *temp;

    temp = (char *)s;
    if (c == '\0')
    {
        while (*temp++ != 0)
            ;
        return (temp);
    }
    while (*temp != 0)
    {
        if (*temp == (char)c)
            return (temp);
        temp++;
    }
    return (0);
}
