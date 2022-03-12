#include "libft.h"

int     ft_atoi(const char *nptr)
{
    int mark;
    int num;

    mark = 1;
    num = 0;
    while (*nptr == '\t' || *nptr == '\t' || *nptr == '\v' || \
    *nptr == '\n' || *nptr == ' ' || *nptr == '\f')
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            mark *= -1;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        num = (num * 10) + (*nptr - '0');
        nptr++;
    }
    return (mark * num);
}
