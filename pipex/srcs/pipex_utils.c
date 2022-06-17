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
	free(path);
	return (arr);
}

char	*find_cmd(char **envp, char **cmd_arg)
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
		free(temp);
		if (cmd == 0)
			return (0);
		if (access(cmd, X_OK) == 0)
			break ;
		free(cmd);
		i++;
	}
	//path free 해줄것
	return (cmd);
}


