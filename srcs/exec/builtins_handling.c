/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:14:59 by marc              #+#    #+#             */
/*   Updated: 2024/08/30 15:10:22 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	is_non_print_builtin(t_prompt *prompt, t_exec *exec)
{
	if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0 && exec->n_cmd == 1)
		return (cd_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0 && ft_strlen2(prompt->cmd) > 1)
		return (export_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "unset", 5) == 0)
		return (unset_builtin(prompt, exec));
	return (0);
}

int	is_builtin(t_prompt *prompt)
{
	if (ft_strncmp(prompt->cmd[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "env", 3) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0)
		return (1);
	else if (ft_strncmp(prompt->cmd[0], "unset", 5) == 0)
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
	else if (ft_strncmp(prompt->cmd[0], "cd", 2) == 0 && exec->n_cmd > 1)
		return (cd_builtin(prompt, exec));
	else if (ft_strncmp(prompt->cmd[0], "export", 6) == 0 && ft_strlen2(prompt->cmd) == 1)
		return (export_builtin(prompt, exec));
	return (1);
}
