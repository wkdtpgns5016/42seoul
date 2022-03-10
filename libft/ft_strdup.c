#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *arr;
    int     i;

    arr = (char *)malloc(sizeof(s) + 1);
    if (arr == 0)
        return (0);
    i = 0;
    while (s[i] != 0)
    {
        arr[i] = s[i];
        i++;
    }
    arr[i] = '\0';
    return (arr);
}
