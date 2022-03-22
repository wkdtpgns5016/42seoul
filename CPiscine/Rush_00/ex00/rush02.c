/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:06:43 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/09 11:17:05 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char	c);

void	draw_rect(int	j, int	x, char	vertex, char	mid)
{
	if (j == 0)
		ft_putchar(vertex);
	else if (j > 0 && j < x - 1)
		ft_putchar(mid);
	else
		ft_putchar(vertex);
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
					draw_rect(j, x, 'A', 'B');
				else if (i > 0 && i < y - 1)
					draw_rect(j, x, 'B', ' ');
				else
					draw_rect(j, x, 'C', 'B');
				j++;
			}
			ft_putchar('\n');
			j = 0;
			i++;
		}
	}
}
