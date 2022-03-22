#include "header.h"

void	get_max(int **dp, int v_len, int h_len, int *max)
{
	int	i;
	int	j;

	i = 0;
	while (++i < v_len)
	{
		j = 0;
		while (++j < h_len)
		{
			*max = ft_max(*max, dp[i][j]);
		}
	}
}

int	get_count(int **dp, int v_len, int h_len, int max)
{
	int	i;
	int	j;
	int	count;

	i = (count = 0);
	while (++i < v_len)
	{
		j = 0;
		while (++j < h_len)
		{
			if (dp[i][j] == max)
				count++;
		}
	}
	return (count);
}

void	get_answer(int **dp, int max, t_point len, t_point *answer)
{
	int		i;
	int		j;
	t_point	*temp;

	i = 0;
	temp = answer;
	while (++i < len.y)
	{
		j = 0;
		while (++j < len.x)
		{
			if (dp[i][j] == max)
			{
				temp->y = i;
				temp->x = j;
				temp++;
			}
		}
	}
	temp->y = 0;
	temp->x = 0;
}

t_point	select_square(int **dp, int v_len, int h_len)
{
	int		max;
	int		count;
	t_point	len;
	t_point	*answer;

	len.x = h_len;
	len.y = v_len;
	max = 0;
	get_max(dp, v_len, h_len, &max);
	count = get_count(dp, v_len, h_len, max);
	answer = (t_point *)malloc(sizeof(t_point) * (count + 1));
	if (!answer)
		return (*answer);
	get_answer(dp, max, len, answer);
	sort_point(answer);
	return (*answer);
}
