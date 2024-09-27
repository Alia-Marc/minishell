/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:06:24 by marc              #+#    #+#             */
/*   Updated: 2024/09/27 17:23:26 by marc             ###   ########.fr       */
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

	while (errno != ECHILD)
		if (wait(&wait_status) == pid && WIFEXITED(wait_status))
			exec->exit = WEXITSTATUS(wait_status);
	if (pid == -1)
		return (127);
	return (exec->exit);
}
