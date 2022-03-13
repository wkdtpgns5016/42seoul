#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    while ((s1[i] != 0 || s2[i] != 0) && i < n)
    {
        if ((unsigned char)s1[i] > (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        else if ((unsigned char)s1[i] < (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%d", ft_strncmp("test\200", "test\0", 6));
}
*/