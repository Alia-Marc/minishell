/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/24 17:48:36 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

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

static int	count_s(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == c && !is_char_in_quotes(s, i))
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static int	fill_tab(char **tab,  char	*s, char c, int count)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (i < count)
	{
		t = 0;
		while (s[j] == c)
			j++;
		while ((s[j] != c && s[j]) || (s[j] == c && is_char_in_quotes(s, j) && s[j]))
		{
			t++;
			j++;
		}
		tab[i] = malloc(sizeof(char) * (t + 1));
		if (!tab[i])
		{
			free_tab(tab, i, count);
			return (1);
		}
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

int	first_pos_quote(char *str, int index)
{
	while(index > 0)


}

char	**split_cmd(char *s, char c)
{
	int		t;
	int		(i) = 0;
	int		(j) = 0;
	int		(count) =  count_s(s, c);
	char	(**tab) = create_tab(s, c);

	if (!s)
		return (NULL);
	while (i < count)
	{
		t = 0;
		while (s[j] == c)
			j++;
		while ((s[j] != c && s[j]) || (s[j] == c && is_char_in_quotes(s, j)))
		{
			if (j == first_pos_quote(s, j) || j == last_pos_quote(s, j))
				j++;
			else
				tab[i][t++] = s[j++];
		}
		tab[i][t] = '\0';
		i++;
	}
	return (tab);
}



// static int  ft_countlen(char *str, char c)
// {
// 	int	index;

// 	index = 0;
// 	if (!str)
// 		return (0);
// 	while ((str[index] && str[index] != c)
// 			|| (str[index] == c && is_char_in_quotes(str, index)))
// 		index++;
// 	return (index - 1);
// }

// static	char	*ft_worddup(char *str, char c)
// {
// 	int		(i) = 0;
// 	int		(index) = 0;
// 	int		(first_pos) = 0;
// 	int		(last_pos) = 0;
// 	char	*dst;

// 	while ((str[index] && str[index] != c) || (str[index] == c && is_char_in_quotes(str, index)))
// 	{
// 			if ((str[index] == 34 || str[index] == 39) && (index == 0))
// 			{
// 				first_pos = index;
// 				index++;
// 			}
// 			else if ((str[index] == 34 || str[index] == 39) && (index == ft_countlen(str, c)))
// 			{
// 				last_pos = index;
// 				index++;
// 			}
// 			else
// 				index++;
// 	}
// 	dst = ft_calloc(sizeof(char), (index + 1));
// 	if (!dst)
// 		return (NULL);
// 	index = 0;
// 	while ((str[index] && str[index] != c) || (str[index] == c && is_char_in_quotes(str, index)))
// 	{
// 			if ((str[index] == 34 || str[index] == 39) && (index == first_pos || index == last_pos))
// 				index++;
// 			else
// 			{
// 				dst[i] = str[index];
// 				index++;
// 				i++;
// 			}
// 	}
// 	dst[index] = '\0';
// 	return (dst);
// }



// char	**split_cmd(char *s, char c)
// {
// 	int		word;
// 	char	**split;

// 	if (!s)
// 		return (NULL);
// 	word = 0;
// 	split = ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
// 	if (!split)
// 		return (NULL);
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s && *s != c)
// 		{
// 			if (!ft_is_redirect(*s))
// 			{
// 				split[word] = ft_worddup(s, c);
// 				if (!split[word])
// 					return (free_cmd(split), NULL);
// 				word++;
// 			}
// 			while ((*s && *s != c))
// 			{
// 				if (*s && (*s == 34 || *s == 39))
// 				{
// 					s++;
// 					while (*s)
// 					{
// 						s++;
// 						if (*s == 34 || *s == 39)
// 							break ;
// 					}
// 				}
// 				if ((*s && *s != c))
// 					s++;
// 			}
// 		}
// 	}
// 	split[word] = NULL;
// 	return (split);
// }
