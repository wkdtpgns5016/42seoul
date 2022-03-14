#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *arr;

    arr = malloc(nmemb * size);
    if (arr == 0)
        return (0);
    ft_bzero(arr, (nmemb * size));
    return (arr);
}
