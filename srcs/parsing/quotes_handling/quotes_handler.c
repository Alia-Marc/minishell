/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:13:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 19:41:45 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	single_quote_closed(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 39 && !is_char_in_double_quotes(str, index))
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
		if (str[index] == 34 && !is_char_in_single_quotes(str, index))
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
	int		i;
	bool	single_quotes_open;
	bool	double_quotes_open;

	i = 0;
	single_quotes_open = false;
	double_quotes_open = false;
	while (str[i])
	{
		if (str[i] == 34 && !is_char_in_single_quotes(str, i))
			double_quotes_open = !double_quotes_open;
		if (str[i] == 39 && !is_char_in_double_quotes(str, i))
			single_quotes_open = !single_quotes_open;
		i++;
	}
	if (single_quotes_open || double_quotes_open)
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
