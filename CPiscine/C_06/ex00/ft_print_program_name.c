/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:24:23 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/20 13:06:03 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char	*str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		argc = 1;
	ft_putstr(argv[argc - 1]);
	write(1, "\n", 1);
	return (0);
}
