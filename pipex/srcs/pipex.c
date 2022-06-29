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

int	child_process(char *cmd, char **envp)
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
	return (fd[0]);
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

void	close_fd(int open_fd[2], int *pipe_list, int list_size, int backup[2])
{
	int	i;

	i = 0;
	close(open_fd[0]);
	close(open_fd[1]);
	while (i < list_size)
	{
		close(pipe_list[i]);
		i++;
	}
	dup2(backup[0], 0);
	dup2(backup[1], 1);
	close(backup[0]);
	close(backup[1]);
}

int	execute_cmds(int ac, char **av, char **envp, int open_fd[2])
{
	int		i;
	int		j;
	int		status;
	int		*pipe_list;
	int		backup_fd[2];

	pipe_list = (int *)malloc(sizeof(int ) * (ac - 4));
	if (pipe_list == 0)
		ft_error("Error", 1);
	backup_fd[0] = dup(0);
	backup_fd[1] = dup(1);
	dup2(open_fd[0], 0);
	i = 0;
	j = 2;
	while (j < ac - 2)
	{
		pipe_list[i] = child_process(av[j++], envp);
		i++;
	}
	dup2(open_fd[1], 1);
	status = last_process(av[ac - 2], envp);
	close_fd(open_fd, pipe_list, i, backup_fd);
	return (status);
}

int	pipex(int ac, char **av, char **envp)
{
	int		open_fd[2];

	open_fd[0] = open(av[1], O_RDONLY);
	if (open_fd[0] < 0)
		perror("Infile Error");
	open_fd[1] = open (av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd[1] < 0)
		ft_error("Outfile Error", 1);
	return (execute_cmds(ac, av, envp, open_fd));
}
