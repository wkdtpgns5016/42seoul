#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  s1_len;
    size_t  s2_len;
    char    *arr;

    if (s1 == 0 || s2 == 0)
        return (0);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    arr = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
    if (arr == 0)
        return (0);
    ft_memcpy(arr, s1, ft_strlen(s1));
    ft_memcpy(arr + s1_len, s2, ft_strlen(s2));
    arr[s1_len + s2_len] = '\0';
    return (arr);
}
