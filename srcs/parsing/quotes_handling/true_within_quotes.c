/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_within_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:43:21 by emilefourni       #+#    #+#             */
/*   Updated: 2024/10/09 16:05:18 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	is_char_in_quotes(char *str, int index)
{
	int		i;
	bool	quotes_open;

	i = 0;
	quotes_open = false;
	while (i <= index)
	{
		if (str[i] == 34 || str[i] == 39)
			quotes_open = !quotes_open;
		i++;
		if (quotes_open && i == index)
			return (1);
	}
	return (0);
}

int	is_char_in_single_quotes(char *str, int index)
{
	int		i;
	bool	quotes_open;

	i = 0;
	quotes_open = false;
	while (i <= index)
	{
		if (str[i] == 39 && !is_char_in_double_quotes(str, i))
			quotes_open = !quotes_open;
		i++;
		if (quotes_open && i == index)
			return (1);
	}
	return (0);
}

int	is_char_in_single_quotes_expand(char *str, int index)
{
	int		i;
	bool	quotes_open;

	i = 0;
	quotes_open = false;
	while (i <= index)
	{
		if (str[i] == 39 && single_quote_closed(str))
			quotes_open = !quotes_open;
		i++;
		if (quotes_open && i == index)
			return (1);
	}
	return (0);
}

int	is_char_in_double_quotes(char *str, int index)
{
	int		i;
	bool	quotes_open;

	i = 0;
	quotes_open = false;
	while (i <= index)
	{
		if (str[i] == 34 && !is_char_in_single_quotes(str, i))
			quotes_open = !quotes_open;
		i++;
		if (quotes_open && i == index)
			return (1);
	}
	return (0);
}
