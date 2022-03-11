#include "libft.h"

size_t  wordcount(char  const *s, char c)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (s[i] != 0)
    {
        if (s[i] != c && s[i + 1] == c)
            count++;
        else if (s[i] != c && s[i + 1] == 0)
            count++;
        i++;
    }
    return (count);
}

char    *init_word(char const *s, size_t idx, size_t len)
{
    char    *word;

    word = (char *)malloc(sizeof(char) * len + 1);
    if (word == 0)
        return (0);
    ft_strlcpy(word, s + idx, len + 1);
    word[len] = 0;
    return (word);
}

void    start_split(char **arr, char const *s, char c, size_t size)
{
    size_t     i;
    size_t     j;
    size_t     k;

    i = 0;
    j = 0;
    while (i < size)
    {
        if (s[j] != c)
        {
            k = 0;
            while (s[j + k] != c && s[j + k] != '\0')
                k++;
            arr[i] = init_word(s, j, k);
            if (arr[i] == 0)
            {
                free(arr);
                arr = 0;
                return ;
            }
            j += k;
            i++;
        }
        else
            j++;
    }
    arr[i] = 0;
}

char    **ft_split(char const *s, char c)
{
    size_t  size;
    char    **arr;

    size = wordcount(s, c);
    arr = (char **)malloc(sizeof(char *) * size + 1);
    if (arr == 0)
        return (0);
    start_split(arr, s, c, size);
    return (arr);
}
