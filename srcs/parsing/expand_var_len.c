/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:42:54 by marc              #+#    #+#             */
/*   Updated: 2024/09/17 19:09:44 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	len_potential_var(char *line, int i)
{
	int	len;

	len = 0;
	if (line[i] == '?')
		return (1);
	while (line[i])
	{
		if (((len == 0 && !ft_isalpha(line[i]))
				|| !ft_isalnum(line[i])) && line[i] != '_')
			return (len);
		len++;
		i++;
	}
	return (len);
}

static int	len_expanded_errno(t_exec *exec)
{
	if (exec->exit >= 100)
		return (3);
	else if (exec->exit >= 10)
		return (2);
	return (1);
}

int	expanded_len(t_exec *exec, char *line)
{
	int	i;
	int	len;
	int	len_var;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			i++;
			len_var = len_potential_var(line, i);
			if (line[i] == '?')
				len += len_expanded_errno(exec) - len_var - 1;
			else
				len += ft_strlen(expanded_var(exec, &line[i], len_var)) - len_var - 1;
		}
		else
			i++;
		len++;
	}
	return (len);
}
