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
		ft_error("Pipe error\n", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Fork error\n", 1);
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
		waitpid(pid, &status, WNOWAIT);
	}
}

void	pipex(char **av, char **envp)
{
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
		perror("Infile Error\n");
	outfile_fd = open (av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_error("Outfile Error\n", 1);
	dup2(infile_fd, 0);
	fork_process(av[2], envp);
	dup2(outfile_fd, 1);
	execute_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{	
	if (ac == 5)
	{
		pipex(av, envp);
	}
	else
		ft_error("Argument Error\n", 1);
}
