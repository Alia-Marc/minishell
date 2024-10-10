/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_skipped_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:21:46 by malia             #+#    #+#             */
/*   Updated: 2024/10/10 14:16:19 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	copy_double(char *s, char *tab, int *j, int *t)
{
	int	skipped;

	skipped = 0;
	if (s[*j] == 34)
	{
		skipped = 1;
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
	return (skipped);
}

int	copy_everything(char *s, char *tab, int *j, int *t)
{
	int	skipped;

	skipped = copy_double(s, tab, j, t);
	if (s[*j] == 39)
	{
		skipped = 1;
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
	return (skipped);
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
