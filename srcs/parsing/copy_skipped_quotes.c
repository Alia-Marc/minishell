/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_skipped_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:21:46 by malia             #+#    #+#             */
/*   Updated: 2024/10/10 13:02:32 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	copy_double(char *s, char *tab, int *j, int *t)
{
	if (s[*j] == 34)
	{
		(*j)++;
		while (s[*j])
		{
			if (s[*j] == 34)
			{
				(*j)++;
				break ;
			}
			tab[(*t)++] = s[(*j)++];
		}
	}
}

void	copy_everything(char *s, char *tab, int *j, int *t)
{
	copy_double(s, tab, j, t);
	if (s[*j] == 39)
	{
		(*j)++;
		while (s[*j])
		{
			if (s[*j] == 39)
			{
				(*j)++;
				break ;
			}
			tab[(*t)++] = s[(*j)++];
		}
	}
}

int	skipped_copy_double(char *s, char *tab, int *j, int *t)
{
	int	skipped;

	skipped = 0;
	if (s[*j] == 34)
	{
		skipped = 1;
		while (s[*j])
		{
			tab[(*t)++] = s[(*j)++];
			if (s[*j] == 34)
			{
				tab[(*t)++] = s[(*j)++];
				break ;
			}
		}
	}
	return (skipped);
}

int	skipped_copy_quotes(char *s, char *tab, int *j, int *t)
{
	int	skipped;

	skipped = skipped_copy_double(s, tab, j, t);
	if (s[*j] == 39)
	{
		skipped = 1;
		while (s[*j])
		{
			tab[(*t)++] = s[(*j)++];
			if (s[*j] == 39)
			{
				tab[(*t)++] = s[(*j)++];
				break ;
			}
		}
	}
	return (skipped);
}
