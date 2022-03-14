#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *temp;
    size_t  len;

    temp = (char *)s;
    len = 0;
    while (*temp != 0)
        temp++;
    while (len++ < ft_strlen(s) + 1)
    {
        if (*temp == (char)c)
            return (temp);
        temp--;
    }
    return (0);
}
