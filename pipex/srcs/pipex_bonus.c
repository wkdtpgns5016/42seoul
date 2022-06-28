/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:29:14 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/28 17:29:15 by sehjang          ###   ########.fr       */
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
		waitpid(pid, 0, WNOHANG);
	}
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
	return (WEXITSTATUS(status));
}

int	pipex(int ac, char **av, char **envp)
{
	int	infile_fd;
	int	outfile_fd;
	int	status;
	int	i;

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
		perror("Infile Error");
	outfile_fd = open (av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_error("Outfile Error", 1);
	dup2(infile_fd, 0);
	i = 2;
	while (i < ac - 2)
		child_process(av[i++], envp);
	dup2(outfile_fd, 1);
	status = last_process(av[ac - 2], envp);
	close(infile_fd);
	close(outfile_fd);
	return (status);
}
