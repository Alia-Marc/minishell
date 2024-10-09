/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:32:13 by marc              #+#    #+#             */
/*   Updated: 2024/10/08 13:07:35 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

t_exec	*init_exec(char **env)
{
	t_exec	*exec;

	exec = (t_exec *)malloc(sizeof(t_exec));
	if (!exec)
		return (NULL);
	exec->env = init_local_env(env);
	exec->fd_in = STDIN_FILENO;
	exec->fd_out = STDOUT_FILENO;
	exec->exit = 0;
	exec->pid = -2;
	exec->n_cmd = 0;
	return (exec);
}

void	reset_exec(t_exec *exec)
{
	if (!isatty(exec->fd_in) && exec->fd_in > 2)
		close(exec->fd_in);
	if (!isatty(exec->fd_out) && exec->fd_out > 2)
		close(exec->fd_out);
	exec->fd_in = STDIN_FILENO;
	exec->fd_out = STDOUT_FILENO;
	exec->pid = -2;
}
