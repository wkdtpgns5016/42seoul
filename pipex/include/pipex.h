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

char	**find_path(char **envp, char *key);
char	*find_cmd(char **cmd_arg, char **envp);
void	execute_cmd(char *cmd, char **envp);
void	ft_free_arr(char ***arr);
void	ft_free(void **ptr);
void	ft_error(char *str, int status);
int		pipex(int ac, char **av, char **envp);
void	get_heredoc(char *limiter);
void	child_process(char *cmd, char **envp);
int		last_process(char *cmd, char **envp);
void	close_fd(int open_fd[2], int backup[2]);


#endif
