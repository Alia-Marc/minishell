/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:42:54 by marc              #+#    #+#             */
/*   Updated: 2024/10/10 11:39:55 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

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

static int	len_skip_single_quotes(char *str, int *i, int *len, bool double_quotes)
{
	int	skipped;

	skipped = 0;
	if (str[*i] == 39 && !double_quotes)
	{
		skipped = 1;
		while (str[*i])
		{
			(*i)++;
			(*len)++;
			if (str[*i] == 39)
			{
				(*i)++;
				(*len)++;
				break ;
			}
		}
	}
	return (skipped);
}

int	expanded_len(t_exec *exec, char *line)
{
	int	i;
	int	len;
	int	len_var;
	bool	double_quotes;

	i = 0;
	len = 0;
	double_quotes = false;
	while (line[i])
	{
		if (len_skip_single_quotes(line, &i, &len, double_quotes))
			continue ;
		if (line[i] == '\"')
			double_quotes = !double_quotes;
		if (line[i] == '$' && line[i + 1])
		{
			i++;
			len_var = len_potential_var(line, i);
			if (line[i] == '?')
				len += len_expanded_errno(exec) - len_var - 1;
			else
				len += ft_strlen(expanded_var(exec, &line[i], len_var))
					- len_var - 1;
		}
		else
			i++;
		len++;
	}
	//ft_fdprintf(2, "len = %d\n", len);
	return (len);
}
