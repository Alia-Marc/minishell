/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:52:36 by malia             #+#    #+#             */
/*   Updated: 2024/08/20 17:48:58 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

int	handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile, int i)
{
	//pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(0);
	exec->pid = fork();
	if (exec->pid == -1)
		exit(0);
	if (exec->pid == 0)
	{
		do_child(fd_infile, exec->fd_out, pipe_fd, i == exec->n_cmd);
		// if (exec->fd_out > 2)
		// 	close(exec->fd_out);
		exec_cmd(prompt, exec);
		exit(0);
	}
	else
	{
		close(pipe_fd[WRITE]);
		// if (exec->fd_out > 2)
		// {
		// 	exec->fd_out = dup2(pipe_fd[READ], exec->fd_out);
		// 	close(pipe_fd[READ]);
		// 	return (-2); 
		// }
		if (fd_infile >= 0)
			fd_infile = dup2(pipe_fd[READ], fd_infile);
		close(pipe_fd[READ]);
		return (fd_infile);
	}
}

void	do_child(int fd_infile, int fd_outfile, int *pipe_fd, int last)
{
	// if (fd_infile < 0 && mid == 0)
	// {
	// 	close(pipe_fd[READ]);
	// 	close(pipe_fd[WRITE]);
	// 	exit_handler(0);
	// }
	close(pipe_fd[READ]);
	//ft_printf("%d", last);
	if (!isatty(fd_infile))
	{
		dup2(fd_infile, STDIN_FILENO);
		close(fd_infile);
	}
	if (!isatty(fd_outfile))
	{
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_outfile);
	}
	else if (!last)
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
}

int	last_pipe(t_prompt *prompt, t_exec *exec, int fd_infile)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		if (fd_infile > 2)
		{
			dup2(fd_infile, STDIN_FILENO);
			close(fd_infile);
		}
		dup2(exec->fd_out, STDOUT_FILENO);
		if (exec->fd_out > 2)
			close(exec->fd_out);
		exec_cmd(prompt, exec);
		exit(0);
	}
	else
	{
		if (fd_infile > 2)
			close(fd_infile);
		return (pid);
	}
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
