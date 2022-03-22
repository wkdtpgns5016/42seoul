#include "header.h"

void	change(int max, int fl_len, char **map, t_point answer)
{
	int		i;
	int		j;
	t_point	len;

	i = 1;
	len.y = atoi(ft_get_nbr(map[0]));
	len.x = ft_strlen(map[1]);
	while (i <= len.y)
	{
		j = 0;
		while (j < len.x)
		{
			if ((answer.y - max < i && i <= answer.y) && \
				(answer.x - max <= j && j < answer.x))
			{
				if (map[i][j] != map[0][fl_len - 2])
					map[i][j] = map[0][fl_len - 1];
			}
			j++;
		}
		i++;
	}
}

void	change_map(int **dp, char **map, t_point answer)
{
	int		max;
	int		fl_len;
	t_point	len;

	max = 0;
	fl_len = ft_strlen(map[0]);
	len.y = atoi(ft_get_nbr(map[0]));
	len.x = ft_strlen(map[1]);
	get_max(dp, len.y + 2, len.x + 2, &max);
	change(max, fl_len, map, answer);
	print_map(map, len.y);
}
