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

int	execute_cmds(int ac, char **av, char **envp, int open_fd[2])
{
	int		j;
	int		status;
	int		backup_fd[2];

	backup_fd[0] = dup(0);
	backup_fd[1] = dup(1);
	j = 2;
	dup2(open_fd[0], 0);
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		j++;
	while (j < ac - 2)
		child_process(av[j++], envp);
	dup2(open_fd[1], 1);
	status = last_process(av[ac - 2], envp);
	close_fd(open_fd, backup_fd);
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
	int		open_fd[2];
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
	open_fd[0] = open(av[1], O_RDONLY);
	if (open_fd[0] < 0)
		perror("Infile Error");
	open_fd[1] = open(av[ac - 1], flag, 0644);
	if (open_fd[1] < 0)
		ft_error("Outfile Error", 1);
	status = execute_cmds(ac, av, envp, open_fd);
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
