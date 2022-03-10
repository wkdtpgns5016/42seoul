#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  src_len;
    size_t  i;

    src_len = ft_strlen(src);
    i = 0;
    while (i < src_len && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    if (len > 0)
        dst[i] = '\0';
    return (src_len);
}
