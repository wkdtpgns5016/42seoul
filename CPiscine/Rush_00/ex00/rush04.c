/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:48:27 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/09 21:48:37 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char	c);

char	set_char(char	head)
{
	if (head == 'B')
		return (' ');
	else
		return ('B');
}

void	draw_rect(int	j, int	x, char	head, char	tail)
{
	char	mid;

	mid = set_char(head);
	if (j == 0)
		ft_putchar(head);
	else if (j > 0 && j < x - 1)
		ft_putchar(mid);
	else
		ft_putchar(tail);
}

void	rush(int	x, int	y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x > 0 && y > 0)
	{
		while (i < y)
		{
			while (j < x)
			{
				if (i == 0)
					draw_rect(j, x, 'A', 'C');
				else if (i > 0 && i < y - 1)
					draw_rect(j, x, 'B', 'B');
				else
					draw_rect(j, x, 'C', 'A');
				j++;
			}
			ft_putchar('\n');
			j = 0;
			i++;
		}
	}
}
