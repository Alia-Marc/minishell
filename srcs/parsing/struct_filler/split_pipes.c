/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:41 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 20:02:01 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_countword(char *str, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index] && str[index] != c)
		{
			count++;
			while ((str[index] && str[index] != c)
				|| (str[index] == c && is_char_in_quotes(str, index)))
				index++;
		}
	}
	return (count);
}

void	free_cmd(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

void	end_tab(char **tab, int *i, bool seen_redirect, int t)
{
	if (tab[*i] && !seen_redirect)
	{
		tab[*i][t] = '\0';
		(*i)++;
	}
}

static	char	*ft_worddup(char *str, int i, char c)
{
	char	*dst;
	int		index;

	index = 0;
	while ((str[i] && str[i] != c)
		|| (str[i] == c && is_char_in_quotes(str, i)))
	{
		i++;
		index++;
	}
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	i -= index;
	index = 0;
	while ((str[i] && str[i] != c)
		|| (str[i] == c && is_char_in_quotes(str, i)))
	{
		dst[index] = str[i];
		index++;
		i++;
	}
	dst[index] = '\0';
	return (dst);
}

char	**split_cmd_pipe(char *s, char c, int i)
{
	char	**split;

	int (word) = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			split[word] = ft_worddup(s, i, c);
			if (!split[word])
				return (free_cmd(split), NULL);
			word++;
			while (s[i] && (s[i] != c
					|| (s[i] == c && is_char_in_quotes(s, i))))
				i++;
		}
	}
	split[word] = NULL;
	return (split);
}
