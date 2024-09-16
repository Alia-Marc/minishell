/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   within_quotes_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:47:45 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/16 16:45:36 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static int	get_last_pos_quote_pipe(char *str, char c, size_t index)
{
	int	last_pos_quote;

	last_pos_quote = 0;
	while (str[index])
	{
		if (str[index] == c)
		{
			last_pos_quote = index;
			while (str[index])
			{
				index++;
				if (str[index] == c)
					return (-1);
			}
			break ;
		}
		index++;
	}
	return (last_pos_quote);
}

static int	get_first_pos_quote_pipe(char *str, char c, int index)
{
	int	first_pos_quote;

	first_pos_quote = 0;
	while (index >= 0)
	{
		if (str[index] == c)
		{
			first_pos_quote = index;
			while(index >= 0)
			{
				index--;
				if (str[index] == c)
					return (-1);
			}
			break ;
		}
		index--;
	}
	return (first_pos_quote);
}

int	within_double_quote_pipe(char *str, int index)
{
	int	first_pos_double;
	int	last_pos_double;

	first_pos_double = get_first_pos_quote_pipe(str, 34, index);
	if (first_pos_double == -1)
		return (0);
	last_pos_double = get_last_pos_quote_pipe(str, 34, index);
	if (last_pos_double == -1)
		return (0);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}

int	within_single_quote_pipe(char *str, int index)
{
	int	last_pos_double;
	int	first_pos_double;

	first_pos_double = get_first_pos_quote_pipe(str, 39, index);
	if (first_pos_double == -1)
		return (0);
	last_pos_double = get_last_pos_quote_pipe(str, 39, index);
	if (last_pos_double == -1)
		return (0);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}
