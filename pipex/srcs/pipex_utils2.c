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

void	child_process(t_info info, char *infile, int pipe[2])
{
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		ft_error("Infile Error", 1);
	dup2(infile_fd, 0);
	close(pipe[0]);
	dup2(pipe[1], 1);
	execute_cmd(info.cmd, info.envp);
}

int	first_process(t_info info, char *infile)
{
	pid_t	pid;
	int		fd[2];
	int		backup;

	backup = dup(0);
	if (pipe(fd) == -1)
		ft_error("Pipe error", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Fork error", 1);
	if (pid == 0)
	{
		child_process(info, infile, fd);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, 0, WNOWAIT);
	}
	return (backup);
}

int	get_exit_status(int status)
{
	return (((status) & 0xff00) >> 8);
}

void	close_fd(int backup_in, int backup_out)
{
	dup2(backup_in, 0);
	dup2(backup_out, 1);
	close(backup_in);
	close(backup_out);
}

int	last_process(t_info info, char *outfile, int backup_fd, int flag)
{
	pid_t	pid;
	int		status;
	int		open_fd[2];

	open_fd[0] = dup(1);
	pid = fork();
	status = 0;
	if (pid == -1)
		ft_error("Fork error", 1);
	else if (pid == 0)
	{
		open_fd[1] = open(outfile, flag, 0644);
		if (open_fd[1] < 0)
			ft_error("Outfile Error", 1);
		dup2(open_fd[1], 1);
		execute_cmd(info.cmd, info.envp);
	}
	else if (pid > 0)
	{
		close_fd(backup_fd, open_fd[0]);
		waitpid(pid, &status, 0);
	}
	return (get_exit_status(status));
}
