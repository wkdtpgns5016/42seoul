#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *temp;

    temp = (unsigned char *)s;
    while (n-- > 0)
    {
        if (*temp == (unsigned char)c)
            return (temp);
        *temp++;
    }
    return (0);
}
