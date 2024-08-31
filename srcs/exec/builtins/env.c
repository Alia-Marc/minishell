/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:13:22 by malia             #+#    #+#             */
/*   Updated: 2024/08/31 02:55:36 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	check_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	env_builtin(t_exec *exec)
{
	int	i;

	i = 0;
	while (exec->env && exec->env[i])
	{
		if (!check_char(exec->env[i], '='))
		{
			i++;
			continue ;
		}
		write(exec->fd_out, exec->env[i], ft_strlen(exec->env[i]));
		write(exec->fd_out, "\n", 1);
		i++;
	}
	return (0);
}
