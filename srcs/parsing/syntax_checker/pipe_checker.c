/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:17:40 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/10 13:56:25 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

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

int	too_many_pipes(char *str, int index)
{

	index++;
	while (str[index])
	{

		if (str[index] == '|')
			return (1);
		if (!ft_isspace(str[index]))
			return (0);
		index++;
	}
	return (1);
}

// int	pipe_checker(char *cmd_line)
// {
// 	size_t	index;
// 	int		is_valid;

// 	index = 0;
// 	is_valid = 1;
// 	while (cmd_line[index])
// 	{
// 		if ((cmd_line[index] == '|') && (ft_indexwhitespace(cmd_line, index)
// 				|| too_many_pipes(cmd_line, index)))
// 			is_valid = 0;
// 		index++;
// 	}
// 	index = 0;
// 	while (cmd_line[index])
// 	{
// 		if (cmd_line[index] == '|' && ft_rev_indexwhitespace(cmd_line, index))
// 			is_valid = 0;
// 		index++;
// 	}
// 	if (is_valid == 0)
// 		ft_bad_pipe_msg();
// 	return (is_valid);
// }

int	pipe_checker(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
		return (ft_bad_pipe_msg(), 0);
	while (str[i])
	{
		if (skipped_quotes(str, &i))
			continue ;
		if (str[i] == '|')
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (!str[i] || str[i] == '|')
				return (ft_bad_pipe_msg(), 0);
		}
		i++;
	}
	return (1);
}
