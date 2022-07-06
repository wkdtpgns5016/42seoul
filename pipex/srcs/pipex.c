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

int	execute_cmds(int ac, char **av, char **envp, int open_fd[2])
{
	int		j;
	int		status;
	int		backup_fd[2];

	backup_fd[0] = dup(0);
	backup_fd[1] = dup(1);
	dup2(open_fd[0], 0);
	j = 2;
	while (j < ac - 2)
		child_process(av[j++], envp);
	dup2(open_fd[1], 1);
	status = last_process(av[ac - 2], envp);
	close_fd(open_fd, backup_fd);
	return (status);
}

int	pipex(int ac, char **av, char **envp)
{
	int		status;
	int		open_fd[2];

	open_fd[0] = open(av[1], O_RDONLY);
	if (open_fd[0] < 0)
		perror("Infile Error");
	open_fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd[1] < 0)
		ft_error("Outfile Error", 1);
	status = execute_cmds(ac, av, envp, open_fd);
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
