/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:12:54 by alia              #+#    #+#             */
/*   Updated: 2024/08/29 03:38:26 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static int	no_args(t_exec *exec)
{
	int	i;
	int	j;
	int	first;

	i = 0;
	while (exec->env && exec->env[i])
	{
		write(STDOUT_FILENO, "declare -x ", 11);
		j = 0;
		first = 0;
		while (exec->env[i][j])
		{
			write(STDOUT_FILENO, &exec->env[i][j], 1);
			if ((exec->env[i][j] == '=' && !first)
				|| (exec->env[i][j + 1] == '\0' && first))
			{
				write(STDOUT_FILENO, "\"", 1);
				first = 1;
			}
			j++;
		}
		i++;
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

int	export_builtin(t_prompt *prompt, t_exec *exec)
{
	if (prompt->cmd[1] == NULL && ft_strlen2(prompt->cmd) == 1)
		return (no_args(exec));
	return (0);
}
