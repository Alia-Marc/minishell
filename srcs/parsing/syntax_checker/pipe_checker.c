/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:17:40 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/31 16:14:04 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_isspaceorpipe(char c)
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
		if (!ft_isspaceorpipe(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_rev_indexwhitespace(char *str, int index)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && i >= index)
	{
		if (!ft_isspaceorpipe(str[i]))
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
