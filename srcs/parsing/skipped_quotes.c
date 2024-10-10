/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipped_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:57:08 by malia             #+#    #+#             */
/*   Updated: 2024/10/10 13:22:03 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	skipped_single_quotes(char *str, int *i, int *skipped)
{
	if (str[*i] == 39)
	{
		*skipped = 1;
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 39)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
}

int	skipped_quotes(char *str, int *i)
{
	int	skipped;

	skipped = 0;
	if (str[*i] == 34)
	{
		skipped = 1;
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 34)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
	skipped_single_quotes(str, i, &skipped);
	return (skipped);
}

void	skip_single_quotes(char *str, int *i)
{
	if (str[*i] == 39)
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 39)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
}

void	skip_in_quotes(char *str, int *i)
{
	if (str[*i] == 34)
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 34)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
	skip_single_quotes(str, i);
}
