#include "header.h"

int	ft_atoi(char *str)
{
	int	idx;
	int	minus;
	int	result;

	idx = 0;
	minus = 1;
	result = 0;
	while (str[idx] == ' ' || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			minus = -minus;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result = result * 10 + (str[idx] - 48);
		idx++;
	}
	return (result * minus);
}
