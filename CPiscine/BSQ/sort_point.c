#include "header.h"

int	comparison(t_point p1, t_point p2)
{
	if (p1.y < p2.y)
		return (1);
	else if (p1.y == p2.y && p1.x < p2.x)
		return (1);
	else if (p1.y > p2.y)
		return (-1);
	else if (p1.y == p2.y && p1.x > p2.x)
		return (-1);
	return (0);
}

void	swap_point(t_point *p1, t_point *p2)
{
	t_point	temp;

	temp.x = p1->x;
	temp.y = p1->y;
	p1->x = p2->x;
	p1->y = p2->y;
	p2->x = temp.x;
	p2->y = temp.y;
}

void	sort_point(t_point *answer)
{
	int		i;
	int		j;
	t_point	*temp;

	i = 0;
	temp = answer;
	while (temp->x != 0)
	{
		i++;
		temp++;
	}
	while (--i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (comparison(answer[j], answer[j + 1]) == -1)
			{
				swap_point(&answer[j], &answer[j + 1]);
			}
			j++;
		}
	}
}
