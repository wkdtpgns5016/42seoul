#include "libft.h"

static int find_tail(const char *haystack, const char *needle)
{
    int  i;
    int  j;
    int  len;

    i = 0;
    len = (int)ft_strlen(haystack);
    if (*needle == 0)
        return (0);
    while (i < len)
    {
        j = 0;
        while (*(haystack - i + len + j) == *(needle + j))
        {
            j++;
            if (*(needle + j) == 0)
                return (len - i);
        }
        i++;
    }
    return (-1);
}

static int find_head(const char *haystack, const char *needle)
{
    int  i;
    int  j;

    i = 0;
    if (*needle == 0)
        return (0);
    while (*(haystack + i) != 0)
    {
        j = 0;
        while (*(haystack + i + j) == *(needle + j))
        {
            j++;
            if (*(needle + j) == 0)
                return (i);
        }
        i++;
    }
    return (-1);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *arr;
    int     head;
    int     tail;
    size_t  set_len;

    set_len = ft_strlen(set);
    arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) - (set_len * 2) + 1));
    head = find_head(s1, set);
    tail = find_tail(s1, set);
    ft_memmove(arr, s1, head);
    ft_memmove(arr + ft_strlen(arr), s1 + head + set_len, tail - head - set_len);
    ft_memmove(arr + ft_strlen(arr), s1 + tail + set_len, ft_strlen(s1 + tail + set_len));
    return (arr);
}
