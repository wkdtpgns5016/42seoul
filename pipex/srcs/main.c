/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:29:01 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/28 17:29:02 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	status;

	if (ac >= 5)
	{
		status = pipex(ac, av, envp);
		exit(status);
	}
	else
		ft_error("Argument Error", 1);
}
