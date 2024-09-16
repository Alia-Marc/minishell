/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:06:45 by malia             #+#    #+#             */
/*   Updated: 2024/09/16 16:20:27 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static int len_expanded_var(t_exec *exec, char *name, int len_var)
{
	int	i;
	int	j;

	i = 0;
	ft_fdprintf(2, "%s %d\n", name, len_var);
	while (exec->env && exec->env[i])
	{
		j = 0;
		while (exec->env[i][j] && exec->env[i][j] != '=')
			j++;
		if (ft_strncmp(name, exec->env[i], len_var) == 0)
		{
			ft_fdprintf(2, "%s\n", &exec->env[i][j + 1]);
			return (ft_strlen(&exec->env[i][j + 1]));
		}
		i++;
	}
	return (0);
}

static int	len_potential_var(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i])
	{
		//ft_fdprintf(2, "%c", line[i]);
		if (((len == 0 && !ft_isalpha(line[i]))
				|| !ft_isalnum(line[i])) && line[i] != '_')
			return (len);
		len++;
		i++;
	}
	return (len);
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
		if (line[i] == '$' && line[i + 1]) // && ft_isalnum(line[i + 1])
		{
			i++;
			len_var = len_potential_var(line, i);
			len += len_expanded_var(exec, &line[i], len_var) - len_var - 1;
		}
		else
			i++;
		len++;
	}
	return (len);
}

// char	*expand_var(t_exec *exec, char *line)
// {
// 	int		i;
// 	char	*result;

// 	i = 0;
// 	if (!line)
// 		return (NULL);
// 	result = (char *)malloc(sizeof(char) * expanded_len(exec, line));
// 	if (!result)
// 		return (line);
// }
