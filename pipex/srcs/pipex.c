/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:12:40 by sehjang           #+#    #+#             */
/*   Updated: 2022/07/04 18:12:41 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pipex(int ac, char **av, char **envp)
{
	int		status;
	int		backup_fd;
	int		flag;
	t_info	info;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	set_info(&info, av[ac - 3], envp);
	backup_fd = first_process(info, av[1]);
	set_info(&info, av[ac - 2], envp);
	status = last_process(info, av[ac - 1], backup_fd, flag);
	return (status);
}

int	main(int ac, char **av, char **envp)
{
	int	status;

	if (ac == 5)
	{
		status = pipex(ac, av, envp);
		exit(status);
	}
	else
		ft_error("Argument Error", 1);
}
