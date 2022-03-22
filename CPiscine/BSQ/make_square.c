#include "header.h"

void	make_square(int **dp, int v_len, int h_len)
{
	int	i;
	int	j;

	i = 0;
	while (++i < v_len)
	{
		j = 0;
		while (++j < h_len)
		{
			if (dp[i][j] != 0)
				dp[i][j] = ft_min(ft_min(dp[i - 1][j - 1], dp[i - 1][j]), \
						 dp[i][j - 1]) + 1;
		}
	}
}
