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

int	pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("error\n");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("error\n");
		return (1);
	}
	else if (pid == 0)
	{
		dup2(fd[1], 1)
	}
	else if (pid > 0)
	{
		dup2(fd[0], 0);
		waitpid(pid, &status, 0);
	}
}

int main(int ac, char **av, char **envp)
{

}