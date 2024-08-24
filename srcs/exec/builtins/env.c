/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:13:22 by malia             #+#    #+#             */
/*   Updated: 2024/08/24 15:23:14 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	env_builtin(t_exec *exec)
{
	int	i;

	i = 0;
	while (exec->env && exec->env[i])
	{
		write(STDOUT_FILENO, exec->env[i], ft_strlen(exec->env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (errno);
}
