#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(char *str, char c, int idx)
{
	int i;
	
	i = 0;
	while (i < idx)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;
	int j;
	
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (check(av[1], av[1][i], i) == 0)
			{
				j = 0;
				while (av[2][j])
				{
					if (av[1][i] == av[2][j])
					{
						ft_putchar(av[1][i]);
						break;
					}
					j++;
				}
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
