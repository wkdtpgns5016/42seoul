/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:23:06 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/19 21:38:15 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char	*str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	size;
	int	result;

	i = 0;
	result = 0;
	size = ft_strlen(s1) + 1;
	while (i < size)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (result);
}

void	swap_str(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < argc - 1)
	{
		temp = i;
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[temp], argv[j]) > 0)
				temp = j;
			j++;
		}
		swap_str(&argv[i], &argv[temp]);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
