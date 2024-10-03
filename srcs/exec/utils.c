/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:06:24 by marc              #+#    #+#             */
/*   Updated: 2024/10/03 07:00:09 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	len_prompt(t_prompt *prompt)
{
	t_prompt	*tmp_prompt;
	int			len;

	tmp_prompt = prompt;
	len = 0;
	while (tmp_prompt)
	{
		len++;
		tmp_prompt = tmp_prompt->next;
	}
	return (len);
}

int	wait_children(t_exec *exec, int pid)
{
	int	wait_status;

	wait_status = -2;
	init_sig(SIGINT, &handle_sigint_cmd);
	while (errno != ECHILD)
		if (wait(&wait_status) == pid && WIFEXITED(wait_status))
			exec->exit = WEXITSTATUS(wait_status);
	if (pid == -1)
		return (127);
	if (WIFSIGNALED(wait_status) && WTERMSIG(wait_status) == SIGQUIT)
	{
		exec->exit = 131;
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g_signal = 0;
	}
	return (exec->exit);
}

void	close_fds(t_exec *exec)
{
	if (!isatty(exec->fd_in) && exec->fd_in > 2)
	{
		close(exec->fd_in);
		exec->fd_in = STDIN_FILENO;
	}
	if (!isatty(exec->fd_out) && exec->fd_out > 2)
	{
		close(exec->fd_out);
		exec->fd_out = STDOUT_FILENO;
	}
}
