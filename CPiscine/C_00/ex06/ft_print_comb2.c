/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:25:58 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/11 10:45:43 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_arr(char	*arr)
{
	int	i;

	i = 0;
	while (i < 2)
		arr[i++] = '0';
}

void	print_arr(char	*arr)
{
	int	i;

	i = 0;
	while (i < 2)
		write(1, &arr[i++], 1);
}

int	is_end_number(char	*arr)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < 2)
	{
		if (arr[i++] == '9')
			check++;
	}
	if (check == 2)
		return (1);
	else
		return (0);
}

void	add_one(char	*arr)
{
	if (arr[1] == '9')
	{
		arr[0]++;
		arr[1] = '0';
	}
	else
		arr[1]++;
}

void	ft_print_comb2(void)
{
	char	first[2];
	char	second[2];

	init_arr(first);
	init_arr(second);
	second[1] = '1';
	while (!is_end_number(first))
	{
		print_arr(first);
		write(1, " ", 1);
		print_arr(second);
		if (is_end_number(second))
		{
			add_one(first);
			second[0] = first[0];
			second[1] = first[1];
			add_one(second);
		}
		else
			add_one(second);
		if (is_end_number(first))
			break ;
		else
			write(1, ", ", 2);
	}
}
