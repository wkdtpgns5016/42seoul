/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:12:36 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/23 09:19:13 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_arr(int *arr)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int	is_possible(int *arr, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (row == arr[i] || i + arr[i] == col + row || \
				i - arr[i] == col - row)
			return (0);
		i++;
	}
	return (1);
}

int	recursive(int *arr, int col, int *total)
{
	int	i;

	i = 0;
	if (col == 10)
	{
		(*total)++;
		print_arr(arr);
		write(1, "\n", 1);
	}
	else
	{
		while (i < 10)
		{
			arr[col] = i;
			if (is_possible(arr, col, i))
				recursive(arr, col + 1, total);
			i++;
		}
	}
	return (*total);
}

int	ft_ten_queens_puzzle(void)
{
	int	total;
	int	i;
	int	arr[10];

	total = 0;
	i = 0;
	while (i < 10)
		arr[i++] = 0;
	return (recursive(arr, 0, &total));
}
