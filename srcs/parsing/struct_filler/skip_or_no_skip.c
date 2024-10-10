/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_or_no_skip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:53:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/10 13:20:53 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

void	skip_or_no_skip(char *s, int *j, int *t, char c)
{
	if (ft_is_redirect(s[*j]))
	{
		*j = redirect_skip(s, *j, c);
		*t = redirect_skip(s, *t, c);
	}
	else
	{
		(*t)++;
		(*j)++;
	}
}

void	end_tab(char **tab, int *i, bool seen_redirect, int t)
{
	if (tab[*i] && !seen_redirect)
	{
		tab[*i][t] = '\0';
		(*i)++;
	}
}
