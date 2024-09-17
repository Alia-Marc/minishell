/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:06:45 by malia             #+#    #+#             */
/*   Updated: 2024/09/17 20:07:30 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

char	*expanded_var(t_exec *exec, char *name, int len_var)
{
	int	i;
	int	j;

	i = 0;
	//ft_fdprintf(2, "%s %d\n", name, len_var);
	while (exec->env && exec->env[i])
	{
		j = 0;
		while (exec->env[i][j] && exec->env[i][j] != '=')
			j++;
		if (ft_strncmp(name, exec->env[i], len_var) == 0)
		{
			//ft_fdprintf(2, "%s\n", &exec->env[i][j + 1]);
			return (&exec->env[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}

static void	copy_expanded_var(char *result, char *value, int *j)
{
	int	i;

	i = 0;
	if (!value)
		return ;
	while (value[i])
	{
		result[*j] = value[i];
		i++;
		(*j)++;
	}
}

void	copy_expand(t_exec *exec, char *line, char *result, int *j)
{
	char	*value;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			i++;
			if (line[i] == '?')
				value = ft_itoa(exec->exit);
			else
				value = expanded_var(exec, &line[i], len_potential_var(line, i));
			copy_expanded_var(result, value, j);
			if (line[i] == '?')
				free(value);
			i += len_potential_var(line, i);
		}
		else
		{
			result[*j] = line[i];
			i++;
			(*j)++;
		}
	}
}

char	*expand_var(t_exec *exec, char *line)
{
	char	*result;
	int		j;

	if (!line)
		return (NULL);
	ft_fdprintf(2, "Expanded len : %d ", expanded_len(exec, line));
	result = (char *)malloc(sizeof(char) * expanded_len(exec, line) + 1);
	if (!result)
		return (line);
	j = 0;
	copy_expand(exec, line, result, &j);
	free(line);
	result[j] = '\0';
	ft_fdprintf(2, "result's len : %d\nexpanded line : %s\n", ft_strlen(result), result);
	return (result);
}
