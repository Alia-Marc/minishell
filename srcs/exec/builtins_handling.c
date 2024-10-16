/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:14:59 by marc              #+#    #+#             */
/*   Updated: 2024/10/08 13:06:28 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

// int	is_modifying_env_builtin(t_prompt *prompt, t_exec *exec)
// {
// 	if (ft_strcmp(prompt->cmd[0], "cd") == 0 && exec->n_cmd == 1)
// 		return (cd_builtin(prompt, exec));
// 	else if (ft_strcmp(prompt->cmd[0], "export") == 0
// 		&& ft_strlen2(prompt->cmd) > 1 && exec->n_cmd == 1)
// 		return (export_builtin(prompt, exec));
// 	else if (ft_strcmp(prompt->cmd[0], "unset") == 0 && exec->n_cmd == 1)
// 		return (unset_builtin(prompt, exec));
// 	return (0);
// }

int	is_builtin(t_prompt *prompt)
{
	if (!prompt->cmd)
		return (0);
	if (ft_strcmp(prompt->cmd[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "env") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "export") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(prompt->cmd[0], "exit") == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_prompt *prompt, t_exec *exec, int *pipe_fd)
{
	close(pipe_fd[READ]);
	if (exec->fd_out <= 2 && prompt->next)
		dup2(pipe_fd[WRITE], exec->fd_out);
	close(pipe_fd[WRITE]);
	if (ft_strcmp(prompt->cmd[0], "pwd") == 0)
		return (pwd_builtin(exec));
	else if (ft_strcmp(prompt->cmd[0], "echo") == 0)
		return (echo_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "env") == 0)
		return (env_builtin(exec));
	else if (ft_strcmp(prompt->cmd[0], "cd") == 0 && exec->n_cmd > 1)
		return (cd_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "export") == 0 && exec->n_cmd > 1)
		return (export_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "exit") == 0)
		return (exit_builtin(prompt, exec));
	return (0);
}

int	exec_solo_builtin(t_prompt *prompt, t_exec *exec)
{
	if (ft_strcmp(prompt->cmd[0], "pwd") == 0)
		return (pwd_builtin(exec));
	else if (ft_strcmp(prompt->cmd[0], "echo") == 0)
		return (echo_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "env") == 0)
		return (env_builtin(exec));
	else if (ft_strcmp(prompt->cmd[0], "cd") == 0)
		return (cd_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "export") == 0)
		return (export_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "unset") == 0)
		return (unset_builtin(prompt, exec));
	else if (ft_strcmp(prompt->cmd[0], "exit") == 0)
		return (exit_builtin(prompt, exec));
	return (0);
}
