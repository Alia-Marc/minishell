/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:13:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/16 16:21:45 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	single_quote_closed(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 39)
		{
			index++;
			while (str[index] != 39 && str[index])
				index++;
			if (!str[index])
				return (0);
			else if (str[index] == 39)
				break ;
		}
		index++;
	}
	return (1);
}

int	double_quote_closed(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 34)
		{
			index++;
			while (str[index] != 34 && str[index])
				index++;
			if (!str[index])
				return (0);
			else if (str[index] == 34)
				break ;
		}
		index++;
	}
	return (1);
}

int	even_nb_outside_quote(char *str)
{
	size_t	i;
	size_t	outside_single_quote;
	size_t	outside_double_quote;

	i = 0;
	outside_single_quote = 0;
	outside_double_quote = 0;
	while (str[i])
	{
		if (str[i] == 39)
			outside_single_quote++;
		else if (str[i] == 34)
			outside_double_quote++;
		i++;
	}
	if (outside_single_quote % 2 != 0 || outside_double_quote % 2 != 0)
		return (0);
	return (1);
}

int	quotes_handler(char *cmd_line)
{
	if (!double_quote_closed(cmd_line) || !single_quote_closed(cmd_line)
		|| !even_nb_outside_quote(cmd_line))
		return (ft_quote_error(), 0);
	return (1);
}
