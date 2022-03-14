#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t  len;
    char    *arr;

    len = ft_strlen(s);
    arr = (char *)malloc(sizeof(char) * (len + 1));
    if (arr == 0)
        return (0);
    ft_strlcpy(arr, s, len + 1);
    return (arr);
}
