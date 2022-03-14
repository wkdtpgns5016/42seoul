#include "libft.h"
#include <stdio.h>
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char    *arr;

    i = 0;
    arr = (char *)malloc(ft_strlen(s) + 1);
    if (arr == 0)
        return (0);
    while (s[i] != 0)
    {
        arr[i] = f(i, s[i]);
        i++;
    }
    arr[i] = '\0';
    return (arr);
}
