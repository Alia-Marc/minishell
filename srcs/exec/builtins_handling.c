/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:14:59 by marc              #+#    #+#             */
/*   Updated: 2024/08/21 13:34:09 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

int	is_builtin(t_prompt *prompt)
{
	if (!ft_strncmp(prompt->cmd[0], "pwd", 3))
		return (1);
	return (0);
}

int	exec_builtin(t_prompt *prompt)
{
	if (!ft_strncmp(prompt->cmd[0], "pwd", 3))
		return (pwd_builtin());
	return (1);
}
