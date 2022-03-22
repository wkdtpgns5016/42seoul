#include "header.h"

#include <stdio.h>

void	bounding(int **dp, int v_len, int h_len)
{
	int	i;

	i = 0;
	while (i < v_len)
	{
		dp[i][0] = 0;
		dp[i][h_len - 1] = 0;
		i++;
	}
	i = 0;
	while (i < h_len)
	{
		dp[0][i] = 0;
		dp[v_len - 1][i] = 0;
		i++;
	}
}

void	initdp(int **dp, int v_len, int h_len)
{
	int	i;
	int	j;

	i = 0;
	while (i <= v_len)
	{
		j = 0;
		while (j <= h_len)
		{
			dp[i][j++] = 1;
		}
		i++;
	}
}

void	in_block(int **dp, char **map, int v_len)
{
	int		i;
	int		j;
	int		fl_len;

	i = 0;
	fl_len = ft_strlen(map[0]);
	while (++i <= v_len)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == map[0][fl_len - 2])
				dp[i][j + 1] = 0;
		}
	}
}

void	mapping(char **map, int v_len, int h_len)
{
	int		i;
	int		**dp;
	t_point	answer;

	dp = (int **)malloc(sizeof(int *) * (v_len + 2));
	i = 0;
	while (i < (v_len + 2))
		dp[i++] = malloc(sizeof(int) * (h_len + 2));
	initdp(dp, v_len, h_len);
	bounding(dp, v_len + 2, h_len + 2);
	in_block(dp, map, v_len);
	make_square(dp, v_len + 2, h_len + 2);
	answer = select_square(dp, v_len + 2, h_len + 2);
	change_map(dp, map, answer);
}
