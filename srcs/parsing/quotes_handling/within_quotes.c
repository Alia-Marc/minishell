/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   within_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:10 by emfourni          #+#    #+#             */
/*   Updated: 2024/08/23 14:31:39 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

size_t	get_last_pos_quote(char *str, char c)
{
	int		i;
	size_t	last_pos_quote;

	i = ft_strlen(str) - 1;
	last_pos_quote = 0;
	while (i >= 0)
	{
		if (str[i] == c)
		{
			last_pos_quote = i;
			break ;
		}
		i--;
	}
	return (last_pos_quote);
}

size_t	get_first_pos_quote(char *str, char c)
{
	size_t	i;
	size_t	first_pos_quote;

	i = 0;
	first_pos_quote = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			first_pos_quote = i;
			break ;
		}
		i++;
	}
	return (first_pos_quote);
}

int	within_double_quote(char *str, size_t index)
{
	size_t	first_pos_double;
	size_t	last_pos_double;

	first_pos_double = get_first_pos_quote(str, 34);
	last_pos_double = get_last_pos_quote(str, 34);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}

int	within_single_quote(char *str, size_t index)
{
	size_t	first_pos_double;
	size_t	last_pos_double;

	first_pos_double = get_first_pos_quote(str, 39);
	last_pos_double = get_last_pos_quote(str, 39);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}
