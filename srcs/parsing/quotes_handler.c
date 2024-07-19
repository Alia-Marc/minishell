/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:13:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 14:45:02 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool within_double_quote(char *str, size_t index)
{
	size_t i;
	size_t first_pos_double;
	size_t last_pos_double;

	i = 0;
	first_pos_double = 0;
	last_pos_double = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			first_pos_double = i;
			break ;
		}
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == 34)
		{
			last_pos_double = i;
			break ;
		}
		i--;
	}
	if (index > first_pos_double && index < last_pos_double)
		return (true);
	return (false);
}

int within_single_quote(char *str, size_t index)
{
	size_t i;
	size_t first_pos_double;
	size_t last_pos_double;

	i = 0;
	first_pos_double = 0;
	last_pos_double = 0;
	while (str[i])
	{
		if (str[i] == 39)
		{
			first_pos_double = i;
			break ;
		}
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == 39)
		{
			last_pos_double = i;
			break ;
		}
		i--;
	}
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}

int	single_quote_closed(char *str)
{
	size_t index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 39 && !within_double_quote(str, index))
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
	size_t index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 34 && !within_single_quote(str, index))
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

int	quotes_handler(char *cmd_line)
{
	if (!double_quote_closed(cmd_line) || !single_quote_closed(cmd_line))
		return (0);
	return (1);
}
