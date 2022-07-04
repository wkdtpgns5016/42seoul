/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:12:53 by sehjang           #+#    #+#             */
/*   Updated: 2022/07/04 18:12:54 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe error", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Fork error", 1);
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
		waitpid(pid, 0, WNOWAIT);
	}
}

int	get_exit_status(int status)
{
	return (((status) & 0xff00) >> 8);
}

int	last_process(char *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == -1)
		ft_error("Fork error", 1);
	else if (pid == 0)
	{
		execute_cmd(cmd, envp);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	return (get_exit_status(status));
}
