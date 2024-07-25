/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:17:40 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/25 14:24:23 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13) || c == '|' )
		return (1);
	return (0);
}

bool	ft_indexwhitespace(char *str, int index)
{
	int	i;

	i = 0;
	while (str[i] && i < index)
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_rev_indexwhitespace(char *str, int index)
{
	int	i;

	i = ft_strlenex(str) - 1;
	while (i >= 0 && i >= index)
	{
		if (!ft_isspace(str[i]))
			return (false);
		i--;
	}
	return (true);
}

int	pipe_checker(char *cmd_line)
{
	size_t	index;
	int		is_valid;

	index = 0;
	is_valid = 1;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '|' && ft_indexwhitespace(cmd_line, index))
			is_valid = 0;
		index++;
	}
	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '|' && ft_rev_indexwhitespace(cmd_line, index))
			is_valid = 0;
		index++;
	}
	return (is_valid);
}