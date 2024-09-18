/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:22:40 by alia              #+#    #+#             */
/*   Updated: 2024/09/01 20:54:02 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	exit_check_first_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
				return (0);
		}
		i++;
	}
	return (1);
}

int	exit_builtin(t_prompt *prompt, t_exec *exec)
{
	int	len_cmd;

	len_cmd = ft_strlen2(prompt->cmd);
	if (exec->n_cmd == 1)
		ft_fdprintf(2, "exit\n");
	if (len_cmd == 1)
		return (exec->exit);
	else if (!exit_check_first_arg(prompt->cmd[1]))
	{
		ft_fdprintf(2, EXIT_NON_NUMERIC, prompt->cmd[1]);
		exec->exit = 2;
	}
	else if (len_cmd > 2)
	{
		ft_fdprintf(2, "kimonOS: exit: too many arguments\n");
		exec->exit = 1;
	}
	else
		exec->exit = ft_atoi(prompt->cmd[1]) % 256;
	return (exec->exit);
}
