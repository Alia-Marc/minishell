/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:14:59 by marc              #+#    #+#             */
/*   Updated: 2024/08/24 15:19:26 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_builtin(t_prompt *prompt)
{
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_prompt *prompt, t_exec *exec)
{
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (pwd_builtin());
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (echo_builtin(prompt));
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (env_builtin(exec));
	return (1);
}
