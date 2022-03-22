/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:33:56 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 21:20:08 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	dict_size(char *dict)
{
	int		fd;
	char	*buff;
	int		cnt;

	cnt = 0;
	buff = malloc(1000 * sizeof(char));
	if (buff != 0)
	{
		fd = open(dict, O_RDONLY);
		if (0 <= fd)
		{
			while (read(fd, buff, 1000))
				cnt++;
			free(buff);
			close(fd);
		}
	}
	return (cnt);
}

char	*ft_read(char *dict)
{
	int		fd;
	char	*buff;
	int		cnt;

	cnt = dict_size(dict);
	buff = malloc(1000 * (cnt + 1) * sizeof(char));
	if (buff != 0)
	{
		fd = open(dict, O_RDONLY);
		if (0 <= fd)
		{
			read(fd, buff, 1000 * (cnt + 1));
			close(fd);
		}
		else
		{
			write(1, "Dict Error\n", 11);
			free(buff);
			return (0);
		}
	}
	return (buff);
}
