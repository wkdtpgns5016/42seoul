#include <stdio.h>
#include "push_swap.h"

static int	is_vaild_num(char *str)
{
	int result;

	result = 0;
	while (*str == '\t' || *str == '\r' || *str == '\v' || \
			*str == '\n' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		result = 1;
	return (result);
}

static int is_intager_arg(int args, char **argc)
{
	int			i;
	long long	num;

	i = 1;
	while (i < args)
	{
		if (!is_vaild_num(argc[i]))
			return (0);
		num = ft_atol(argc[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate_arg(int args, char **argc)
{
	int	i;
	int	j;
	int len;

	i = 1;
	while (i < args - 1)
	{
		j = i + 1;
		while (j < args)
		{
			if (i != j)
			{
				if (ft_strlen(argc[i]) > ft_strlen(argc[j]))
					len = ft_strlen(argc[i]);
				else
					len = ft_strlen(argc[j]);
				if (ft_strncmp(argc[i], argc[j], len) == 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	error_message(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

void	check_vaild_arg(int args, char **argc)
{
	if(args <= 1)
		error_message();
	if(!is_intager_arg(args, argc))
		error_message();
	if(is_duplicate_arg(args, argc))
		error_message();
}