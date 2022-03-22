/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:33:42 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/23 19:34:25 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	str_error(char *str)
{
	if (str != 0)
		free(str);
	write(1, "Error\n", 6);
}

char	*check_argc(int argc, char **argv)
{
	char	*str;

	str = 0;
	if (argc == 2)
	{
		str = ft_read("numbers.dict");
		if (!ft_valid(argv[1]))
		{	
			str_error(str);
			return (0);
		}
	}
	else if (argc == 3)
	{
		str = ft_read(argv[1]);
		if (!ft_valid(argv[2]))
		{
			str_error(str);
			return (0);
		}
	}
	else
		write(1, "Error\n", 6);
	return (str);
}

void	start_rush(int *num, t_dict *dicts)
{
	ft_print(num, dicts);
	free(dicts);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**arr;
	t_dict	*dicts;
	int		*num;

	str = check_argc(argc, argv);
	if (str == 0)
		return (0);
	arr = ft_split(str, "\n");
	free(str);
	if (arr == 0)
		return (0);
	if (!is_dict_valid(arr))
	{
		free(arr);
		return (0);
	}
	dicts = ft_make_dicts(arr);
	if (argc == 2)
		num = ft_div3(ft_atoi(argv[1]));
	else
		num = ft_div3(ft_atoi(argv[2]));
	if (dicts != 0)
		start_rush(num, dicts);
}
