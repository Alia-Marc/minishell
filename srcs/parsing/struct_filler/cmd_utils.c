/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/28 16:46:07 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

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

int	is_in_redirect(char *s, int index, int max_index)
{
	while (index < max_index)
	{
		if (ft_is_redirect(s[index]) && !is_char_in_quotes(s, index))
			return (1);
		index++;
	}
	return (0);
}

int is_char_in_quotes(char *str, int index)
{
    int i;
    bool quotesOpen;

    i = 0;
    quotesOpen = false;
    while (i <= index)
    {
        if (str[i] == 34 || str[i] == 39)
            quotesOpen = !quotesOpen;
        i++;
        if (quotesOpen && i == index)
            return (1);
    }
    return (0);
}

static void	free_tab(char **tab, size_t k, size_t max)
{
	size_t	i;

	i = 0;
	while (i != k)
	{
		free(tab[i]);
	}
	free(tab[max]);
	free(tab);
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

static int	count_s(char *s, char c)
{
	int		(i) = 0;
	int		(count) = 1;

	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (ft_is_redirect(s[i]) && !is_char_in_quotes(s, i))
			i = redirect_skip(s, i, c);
		else if (s[i] == c && ((!is_char_in_quotes(s, i) && !ft_is_redirect(s[i + 1]))
				|| (!is_char_in_quotes(s, i) && check_for_cmd(s, i, c))))
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

char	*tab_alloc(char **tab, int index_string, int count, int index_char)
{
	tab[index_string] = malloc(sizeof(char) * (index_char + 1));
	if (!tab[index_string])
		return (free_tab(tab, index_string, count), NULL);
	return (tab[index_string]);
}

static int	fill_tab(char **tab,  char	*s, char c, int count)
{
	int	(i) = 0;
	int	(j) = 0;
	int	t;

	while (i < count)
	{
		t = 0;
		while (s[j] == c)
			j++;
		while ((s[j] != c && s[j]) || (s[j] == c && is_char_in_quotes(s, j) && s[j]))
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
			tab[i] = tab_alloc(tab, i, count, t);
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

int	quotes_removal(char *s, int j, int t, char *tab)
{
	if (((t == 0 && (s[j] == 34 || s[j] == 39))) || (t == ft_strlen(tab) && (s[j] == 34 || s[j] == 39)))
		return (1);
	return (0);
}

char	**ft_strdupsplit(char **tab, int count_words, char *s, char c)
{
	int		t;
	int		(i) = 0;
	int		(j) = 0;
	bool	(seen_redirect);
	
	while (i < count_words)
	{
		t = 0;
		seen_redirect = false;
		while (s[j] == c)
			j++;
		while ((s[j] != c && s[j]) || (s[j] == c && is_char_in_quotes(s, j)))
		{
			if (quotes_removal(s, j, t, tab[i]))
				j++;
			if (ft_is_redirect(s[j]) && !is_char_in_quotes(s, j))
			{
				j = redirect_skip(s, j, c);
				seen_redirect = true;
			}
			else if (s[j] && (s[j] != c || (s[j] == c && is_char_in_quotes(s, j))))
				tab[i][t++] = s[j++];
		}
		if (tab[i] && !seen_redirect)
		{
			tab[i][t] = '\0';
			i++;
		}
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

void	free_cmd(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;;
	}
	free(str);
}

int main(int argc, char *argv[])
{
	char **split;
	int	index;
	int nb_words;

	(void) argc;
	
	index = 0;
	split = split_cmd(argv[1], '|');
	nb_words = count_s(argv[1], '|');
	while (split[index])
		printf("word : %s\n %d\n", split[index++], nb_words);
	free_cmd(split);
	return 0;
}
