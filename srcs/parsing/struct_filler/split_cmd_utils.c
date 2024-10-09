/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:11:19 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 19:28:18 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	redirect_skip(char *s, int j, char c)
{
	while (s[j] && (ft_is_redirect(s[j]) || (s[j] == c)))
		j++;
	while (s[j] && s[j] != c)
		j++;
	while (s[j] && s[j] == c)
	{
		if (s[j + 1] != c)
			break ;
		j++;
	}
	return (j);
}

int	check_for_cmd(char *s, int index, char c)
{
	while (s[index])
	{
		if (ft_is_redirect(s[index]) && !is_char_in_quotes(s, index))
			index = redirect_skip(s, index, c);
		if (s[index] && s[index] != c)
			return (1);
		if (s[index])
			index++;
	}
	return (0);
}

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

char	*tab_alloc(char **tab, int index_string, int index_char)
{
	tab[index_string] = ft_calloc(sizeof(char), index_char + 1000);
	if (!tab[index_string])
		return (ft_free_tab(tab), NULL);
	return (tab[index_string]);
}
