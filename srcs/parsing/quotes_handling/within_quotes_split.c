/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   within_quotes_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:01:18 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/18 20:44:44 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	get_last_pos_quote2(char *str, char c)
{
	int		i;
	int	last_pos_quote;

	i = 0;
	last_pos_quote = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			while (str[i] && str[i] != c)
				i++;
			last_pos_quote = i;
			break ;
		}
		i++;
	}
	return (last_pos_quote);
}

int	get_first_pos_quote2(char *str, char c)
{
	int	i;
	int	first_pos_quote;

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

int	within_double_quote2(char *str, int index)
{
	int	first_pos_double;
	int	last_pos_double;

	first_pos_double = get_first_pos_quote2(str, 34);
	last_pos_double = get_last_pos_quote2(str, 34);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}

int	within_single_quote2(char *str, int index)
{
	int	first_pos_double;
	int	last_pos_double;

	first_pos_double = get_first_pos_quote2(str, 39);
	last_pos_double = get_last_pos_quote2(str, 39);
	if (index > first_pos_double && index < last_pos_double)
		return (1);
	return (0);
}
