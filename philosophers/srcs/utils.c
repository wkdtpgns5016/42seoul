
#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	int	mark;
	int	num;

	mark = 1;
	num = 0;
	while (*nptr == '\t' || *nptr == '\r' || *nptr == '\v' || \
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

void	print_message(char *str, int philo_num, int time)
{
	printf("%d %d %s\n", time, philo_num, str);
}
