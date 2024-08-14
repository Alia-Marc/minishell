/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:06:24 by marc              #+#    #+#             */
/*   Updated: 2024/08/14 06:23:55 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	len_prompt(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;

	tmp_prompt = prompt;
	exec->n_cmd = 0;
	while (tmp_prompt)
	{
		exec->n_cmd++;
		tmp_prompt = tmp_prompt->next;
	}
}

int	wait_children(int pid)
{
	int	wait_status;
	int	error_status;

	while (errno != ECHILD)
		if (wait(&wait_status) == pid && WIFEXITED(wait_status))
			error_status = WEXITSTATUS(wait_status);
	if (pid == -1)
		return (127);
	return (error_status);
}
