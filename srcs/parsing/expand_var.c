/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:06:45 by malia             #+#    #+#             */
/*   Updated: 2024/10/09 21:59:55 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

char	*expanded_var(t_exec *exec, char *name, int len_var)
{
	int	i;
	int	j;

	i = 0;
	while (exec->env && exec->env[i])
	{
		j = 0;
		while (exec->env[i][j] && exec->env[i][j] != '=')
			j++;
		if (ft_strncmp(name, exec->env[i], len_var) == 0)
		{
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

static void	copy_skip_single_quotes(char *str, int *i, char *result, int *j)
{
	while (str[*i])
	{
		result[*j] = str[*i];
		(*i)++;
		(*j)++;
		if (str[*i] == 39)
		{
			result[*j] = str[*i];
			(*i)++;
			(*j)++;
			break ;
		}
	}
}

// static int	copy_skip_single_quotes(char *str, int *i, char *result, int *j)
// {
// 	bool	double_quotes;

// 	double_quotes = false;
// 	if (str[*i] == '\'' && !double_quotes)
// 	{
// 		while (str[*i])
// 		{
// 			result[*j] = str[*i];
// 			(*i)++;
// 			(*j)++;
// 			if (str[*i] == 39)
// 			{
// 				result[*j] = str[*i];
// 				(*i)++;
// 				(*j)++;
// 				break ;
// 			}
// 		return (1);
// 	}
// 	if (str[*i] == '\"')
// 		double_quotes = !double_quotes;
// 	}
// 	return (0);
// }

void	copy_expand(t_exec *exec, char *line, char *result, int *j)
{
	char	*val;
	int		i;
	bool	double_quotes;

	i = 0;
	double_quotes = false;
	while (line[i])
	{
		if (line[i] == '\'' && !double_quotes)
		{
			copy_skip_single_quotes(line, &i, result, j);
			continue ;
		}
		if (line[i] == '\"')
			double_quotes = !double_quotes;
		if (line[i] == '$' && line[i + 1])
		{
			i++;
			if (line[i] == '?')
				val = ft_itoa(exec->exit);
			else
				val = expanded_var(exec, &line[i], len_potential_var(line, i));
			copy_expanded_var(result, val, j);
			if (line[i] == '?')
				free(val);
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
	result = (char *)malloc(sizeof(char) * expanded_len(exec, line) + 1);
	if (!result)
		return (line);
	j = 0;
	copy_expand(exec, line, result, &j);
	free(line);
	result[j] = '\0';
	return (result);
}
