/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:34:30 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/17 14:34:31 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fork_process(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute_cmd(cmd, envp);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, &status, 0);
	}
}

void	pipex(char **av, char **envp)
{
	int	in;
	int	out;

	in = open(av[1], O_RDONLY, 0777);
	out = open (av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fork_process(av[2], envp);
	fork_process(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
	{
		pipex(av, envp);
	}
}
