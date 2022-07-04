/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:45:32 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/17 14:45:33 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(char *str, int status)
{
	perror(str);
	exit(status);
}

void	close_fd(int open_fd[2], int backup[2])
{
	int	i;

	i = 0;
	dup2(backup[0], 0);
	dup2(backup[1], 1);
	close(open_fd[0]);
	close(open_fd[1]);
	close(backup[0]);
	close(backup[1]);
}

char	**find_path(char **envp, char *key)
{
	char	**arr;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], key, ft_strlen(envp[i])))
		{
			path = ft_substr(envp[i], ft_strlen(key), ft_strlen(envp[i]));
			if (path == 0)
				return (0);
			break ;
		}
		i++;
	}
	arr = ft_split(path, ':');
	if (arr == 0)
		return (0);
	ft_free((void **)&path);
	return (arr);
}

char	*find_cmd(char **cmd_arg, char **envp)
{
	int		i;
	char	*cmd;
	char	*temp;
	char	**path;

	i = 0;
	path = find_path(envp, "PATH=");
	if (path == 0)
		return (0);
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		if (temp == 0)
			return (0);
		cmd = ft_strjoin(temp, cmd_arg[0]);
		ft_free((void **)&temp);
		if (cmd == 0)
			return (0);
		if (access(cmd, X_OK) == 0)
			break ;
		ft_free((void **)&cmd);
		i++;
	}
	ft_free_arr(&path);
	return (cmd);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;

	cmd_arg = ft_split(cmd, ' ');
	if (cmd_arg == 0)
		return ;
	if (access(*cmd_arg, X_OK) == 0)
		cmd_path = ft_strdup(*cmd_arg);
	else
		cmd_path = find_cmd(cmd_arg, envp);
	if (cmd_path == 0)
	{
		ft_free_arr(&cmd_arg);
		ft_error("command not found", 127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		ft_error("Execve error", 1);
}
