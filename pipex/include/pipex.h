/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:34:47 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/17 14:34:47 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info
{
	char	*cmd;
	char	**envp;
}	t_info;

char	**find_path(char **envp, char *key);
char	*find_cmd(char **cmd_arg, char **envp);
void	execute_cmd(char *cmd, char **envp);
void	ft_free_arr(char ***arr);
void	ft_free(void **ptr);
void	ft_error(char *str, int status);
int		pipex(int ac, char **av, char **envp);
int		first_process(t_info info, char *infile);
int		last_process(t_info info, char *outfile, int backup_fd, int flag);
void	set_info(t_info *info, char *cmd, char **envp);

#endif
