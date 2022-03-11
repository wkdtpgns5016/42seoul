#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *arr;

    arr = ft_strdup(s1);

    return (arr);
}

char    *del_first_set(char *s1)
{
    
}

char    *ft_strrstr(const char *haystack, const char *needle)
{
    size_t  i;
    size_t  j;
    size_t  len;

    i = 0;
    len = ft_strlen(haystack);
    if (*needle == 0)
        return ((char *)haystack);
    while (i < len)
    {
        j = 0;
        while (*(haystack + len + j) == *(needle + j))
        {
            j++;
            if (*(needle + j) == 0)
                return ((char *)haystack + len);
        }
        haystack--;
        i++;
    }
    return (0);
}

char    *ft_strstr(const char *haystack, const char *needle)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (*needle == 0)
        return ((char *)haystack);
    while (*haystack != 0)
    {
        j = 0;
        while (*(haystack + j) == *(needle + j))
        {
            j++;
            if (*(needle + j) == 0)
                return ((char *)haystack);
        }
        haystack++;
        i++;
    }
    return (0);
}

#include <stdio.h>

int main(void)
{
    char *test = "this is test code.";

    printf("%s", ft_strstr(test, "is"));
}