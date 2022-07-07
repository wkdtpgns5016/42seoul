/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:13:13 by sehjang           #+#    #+#             */
/*   Updated: 2022/07/04 18:13:13 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	mid_process(t_info info)
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
		execute_cmd(info.cmd, info.envp);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, 0, WNOWAIT);
	}
}

int	execute_cmds(int ac, char **av, char **envp, int flag)
{
	int		j;
	int		status;
	int		backup_fd;
	t_info	info;

	j = 2;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		j++;
	set_info(&info, av[j++], envp);
	backup_fd = first_process(info, av[1]);
	while (j < ac - 2)
	{
		set_info(&info, av[j++], envp);
		mid_process(info);
	}
	set_info(&info, av[ac - 2], envp);
	status = last_process(info, av[ac - 1], backup_fd, flag);
	return (status);
}

void	get_heredoc(char *limiter)
{
	char	buffer[100];
	int		fd;
	int		size;
	char	*check;

	check = ft_strjoin(limiter, "\n");
	if (check == 0)
		ft_error("Error", 1);
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_error("Error", 1);
	while (1)
	{
		ft_putstr_fd(">", 1);
		size = read(0, buffer, 100);
		if (size < 0)
			ft_error("Error", 1);
		buffer[size] = '\0';
		if (ft_strncmp(buffer, check, ft_strlen(buffer)) == 0)
			break ;
		write(fd, buffer, ft_strlen(buffer));
	}
	ft_free((void **)&check);
	close(fd);
}

int	pipex(int ac, char **av, char **envp)
{
	int		status;
	int		here_doc;
	int		flag;

	here_doc = 0;
	flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		here_doc = 1;
	if (here_doc)
	{
		get_heredoc(av[2]);
		flag = O_WRONLY | O_CREAT | O_APPEND;
	}
	status = execute_cmds(ac, av, envp, flag);
	if (here_doc)
		unlink("./here_doc");
	return (status);
}

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
