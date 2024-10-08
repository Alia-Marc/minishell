/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checker2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:17:57 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/08 14:00:59 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_isspace_or_redirect(char c)
{
	if (ft_isspace(c) || (c == '>' || c == '<'))
		return (1);
	return (0);
}

int	ft_dollarsign_redirect(char *cmd_line)
{
	int index;

	index = 0;
	while (cmd_line[index])
	{
		if (ft_is_redirect(cmd_line[index]))
		{
			if (cmd_line[index + 1] == '$' && (cmd_line[index + 2] != '$'
				|| ft_isspace(cmd_line[index + 2])))
				return (ft_redirect_name_empty(), 0);
		}
		index++;
	}
	return (1);
}

int	space_between_cmd_redirect(char *cmd_line)
{
	int	index;

	index = 0;
	while (cmd_line[index])
	{
		if (ft_is_redirect(cmd_line[index]))
		{
			if (index > 0 && (!ft_isspace_or_redirect(cmd_line[index - 1])
				&& !is_char_in_quotes(cmd_line, index)))
				return (0);
		}
		index++;
	}
	return (1);
}

