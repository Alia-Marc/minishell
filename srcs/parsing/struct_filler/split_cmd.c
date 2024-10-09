/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 19:03:35 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static int	count_s(char *s, char c)
{
	int (i) = 0;
	int (count) = 1;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		skip_in_quotes(s, &i);
		if (ft_is_redirect(s[i]))
			i = redirect_skip(s, i, c);
		else if (s[i] == c && check_for_cmd(s, i, c))
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static int	fill_tab(char **tab, char	*s, char c, int count)
{
	int	t;

	int (i) = 0;
	int (j) = 0;
	while (i < count)
	{
		t = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			if (ft_is_redirect(s[j]))
			{
				j = redirect_skip(s, j, c);
				t = redirect_skip(s, t, c);
			}
			else
			{
				t++;
				j++;
			}
		}
		if (!is_in_redirect(s, j - t, j))
			tab[i] = tab_alloc(tab, i, t);
		if (!is_in_redirect(s, j - t, j))
			i++;
	}
	return (0);
}

static char	**create_tab(char *s, char c)
{
	char	**tab;
	int		count;

	count = count_s(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	if (fill_tab(tab, s, c, count))
		return (NULL);
	tab[count] = 0;
	return (tab);
}

void	end_tab(char **tab, int *i, bool seen_redirect, int t)
{
	if (tab[*i] && !seen_redirect)
	{
		tab[*i][t] = '\0';
		(*i)++;
	}
}

static char	**ft_strdupsplit(char **tab, int count_words, char *s, char c)
{
	int (t) = 0;
	int (i) = 0;
	int (j) = 0;
	bool (seen_redirect);
	while (i < count_words)
	{
		t = 0;
		seen_redirect = false;
		while (s[j] == c)
			j++;
		while ((s[j] != c && s[j]))
		{
			copy_everything(s, tab[i], &j, &t);
			if (ft_is_redirect(s[j]))
			{
				j = redirect_skip(s, j, c);
				seen_redirect = true;
			}
			else if (s[j] && s[j] != c)
				tab[i][t++] = s[j++];
		}
		end_tab(tab, &i, seen_redirect, t);
	}
	return (tab);
}

char	**split_cmd(char *s, char c)
{
	int		count;
	char	**tab;

	if (!s)
		return (NULL);
	count = count_s(s, c);
	tab = create_tab(s, c);
	tab = ft_strdupsplit(tab, count, s, c);
	return (tab);
}
