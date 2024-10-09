/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:52:36 by malia             #+#    #+#             */
/*   Updated: 2024/10/09 07:13:10 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(0);
	exec->pid = fork();
	if (exec->pid == -1)
		exit(0);
	if (exec->pid == 0 && prompt->cmd[0])
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if (is_builtin(prompt))
			exec->exit = exec_builtin(prompt, exec, pipe_fd);
		else
		{
			do_child(fd_infile, exec, pipe_fd, prompt);	
			//ft_fdprintf(2, "true cmd\n");
		}
		return (exec->pid);
	}
	else
	{
		close(pipe_fd[WRITE]);
		if (!isatty(fd_infile) && fd_infile > 2)
			close(fd_infile);
		//exec->exit = is_modifying_env_builtin(prompt, exec);
		return (pipe_fd[READ]);
	}
}

void	do_child(int fd_in, t_exec *exec, int *pipe_fd, t_prompt *prompt)
{
	// if (fd_in < 0 && mid == 0)
	// {
	// 	close(pipe_fd[READ]);
	// 	close(pipe_fd[WRITE]);
	// 	exit_handler(0);
	// }
	close(pipe_fd[READ]);
	if (!isatty(fd_in) && fd_in > 2)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (!isatty(exec->fd_out) && exec->fd_out > 2)
	{
		dup2(exec->fd_out, STDOUT_FILENO);
		close(exec->fd_out);
	}
	else if (prompt->next)
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	exec_cmd(prompt, exec);
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


// int	handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile, int i)
// {
// 	//pid_t	pid;
// 	int		pipe_fd[2];

// 	if (pipe(pipe_fd) == -1)
// 		exit(0);
// 	exec->pid = fork();
// 	if (exec->pid == -1)
// 		exit(0);
// 	if (exec->pid == 0)
// 	{
// 		do_child(fd_infile, exec->fd_out, pipe_fd, i == exec->n_cmd);
// 		// if (exec->fd_out > 2)
// 		// 	close(exec->fd_out);
// 		exec_cmd(prompt, exec);
// 		exit(0);
// 	}
// 	else
// 	{
// 		close(pipe_fd[WRITE]);
// 		// if (exec->fd_out > 2)
// 		// {
// 		// 	exec->fd_out = dup2(pipe_fd[READ], exec->fd_out);
// 		// 	close(pipe_fd[READ]);
// 		// 	return (-2); 
// 		// }
// 		if (fd_infile >= 0)
// 			fd_infile = dup2(pipe_fd[READ], fd_infile);
// 		close(pipe_fd[READ]);
// 		return (fd_infile);
// 	}
// }
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
