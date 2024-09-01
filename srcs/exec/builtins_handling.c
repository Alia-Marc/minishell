/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:14:59 by marc              #+#    #+#             */
/*   Updated: 2024/09/02 00:35:27 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_modifying_env_builtin(t_prompt *prompt, t_exec *exec)
{
	if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0 && exec->n_cmd == 1)
		return (cd_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0
		&& ft_strlen2(prompt->cmd) > 1 && exec->n_cmd == 1)
		return (export_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "unset", 5) == 0 && exec->n_cmd == 1)
		return (unset_builtin(prompt, exec));
	return (0);
}

int	is_builtin(t_prompt *prompt)
{
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "exit", 4) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_prompt *prompt, t_exec *exec, int *pipe_fd)
{
	close(pipe_fd[READ]);
	if (exec->fd_out <= 2 && prompt->next)
		dup2(pipe_fd[WRITE], exec->fd_out);
	close(pipe_fd[WRITE]);
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (pwd_builtin(exec));
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (echo_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (env_builtin(exec));
	else if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0 && exec->n_cmd > 1)
		return (cd_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0 && exec->n_cmd > 1)
		return (export_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "exit", 4) == 0)
		return (exit_builtin(prompt, exec));
	return (0);
}

int	exec_solo_builtin(t_prompt *prompt, t_exec *exec)
{
	// if (!isatty(exec->fd_in) && exec->fd_in > 2)
	// {
	// 	dup2(exec->fd_in, STDIN_FILENO);
	// 	close(exec->fd_in);
	// }
	// if (!isatty(exec->fd_out) && exec->fd_out > 2)
	// {
	// 	dup2(exec->fd_out, STDOUT_FILENO);
	// 	close(exec->fd_out);
	// }
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (pwd_builtin(exec));
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (echo_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (env_builtin(exec));
	else if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0)
		return (cd_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0)
		return (export_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "unset", 5) == 0)
		return (unset_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "exit", 4) == 0)
		return (exit_builtin(prompt, exec));
	return (0);
}
