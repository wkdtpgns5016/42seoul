#include "libft.h"

// little null포인터로 넘어올경우 생각하기
char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (*little == 0)
        return ((char *)big);
    while (*big != 0 && i < len)
    {
        j = 0;
        while (*(big + j) == *(little + j) && j < len)
        {
            j++;
            if (*(little + j) == 0)
                return ((char *)big);
        }
        big++;
        i++;
    }
    return (0);
}
