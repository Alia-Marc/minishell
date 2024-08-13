/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:52:36 by malia             #+#    #+#             */
/*   Updated: 2024/08/13 07:30:52 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

int	handle_pipe(t_prompt *prompt, t_exec *exec)
{
	// pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(0);
	exec->pid = fork();
	if (exec->pid == -1)
		exit(0);
	if (exec->pid == 0)
	{
		do_child(exec->fd_in, pipe_fd);
		exec_cmd(prompt, exec);
		exit(0);
	}
	else
	{
		close(pipe_fd[WRITE]);
		if (exec->fd_in >= 0)
			exec->fd_in = dup2(pipe_fd[READ], exec->fd_in);
		close(pipe_fd[READ]);
		return (exec->fd_in);
	}
}

void	do_child(int fd_infile, int *pipe_fd)
{
	// if (fd_infile < 0 && mid == 0)
	// {
	// 	close(pipe_fd[READ]);
	// 	close(pipe_fd[WRITE]);
	// 	exit_handler(0);
	// }
	close(pipe_fd[READ]);
	if (fd_infile > 2)
	{
		dup2(fd_infile, STDIN_FILENO);
		close(fd_infile);
	}
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
}

// int	mid_pipe(char *cmd, char **env, int fd_infile)
// {
// 	pid_t	pid;
// 	int		pipe_fd[2];

// 	if (pipe(pipe_fd) == -1)
// 		exit(0);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);
// 	if (pid == 0)
// 	{
// 		do_child(fd_infile, pipe_fd, 1);
// 		exec(cmd, env);
// 		exit(0);
// 	}
// 	else
// 	{
// 		close(pipe_fd[WRITE]);
// 		if (fd_infile >= 0)
// 			fd_infile = dup2(pipe_fd[READ], fd_infile);
// 		close(pipe_fd[READ]);
// 		return (fd_infile);
// 	}
// }
