/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/11 17:17:48 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_countword(char *str, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index] && str[index] != c)
		{
			count++;
			while ((str[index] && str[index] != c)
					|| (within_single_quote(str, index)
					|| within_double_quote(str, index)))
				index++;
		}
	}
	return (count);
}

static	char	*ft_worddup(char *str, char c)
{
	size_t	index;
	char	*dst;

	index = 0;
	while ((str[index] && str[index] != c)
			|| (within_single_quote(str, index) || within_double_quote(str, index)))
		index++;
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while ((str[index] && str[index] != c)
			|| (within_single_quote(str, index) || within_double_quote(str, index)))
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

void	free_cmd(char **str, int i)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

// char	**split_cmd(char *str, char c)
// {
// 	int		word;
// 	int		index;
// 	char	**split;

// 	word = 0;
// 	index = 0;
// 	split = malloc(sizeof(char *) * (ft_countword(str, c) + 1));
// 	if (!split)
// 		return (NULL);
// 	while (str[index])
// 	{
// 		while (str[index] && str[index] == c)
// 			index++;
// 		if (str[index] && str[index] != c)
// 		{
// 			if (str[index] == '$' && within_double_quote(str, index))
// 				split[word] =
// 			split[word] = ft_strdupnospace(str, index);
// 			if (!split[word])
// 				return (free_cmd(split, word), NULL);
// 			word++;
// 		}
// 	}
// }

char	**split_cmd(char *s, char c)
{
	int		word;
	char	**split;

	word = 0;
	split = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			// if (*s == '$' && within_double_quote(s, index))
			// 	split[word] = ft_strdupenv(s, c);
			split[word] = ft_worddup(s, c);
			if (!split[word])
				return (free_cmd(split, word), NULL);
			word++;
			while ((*s && *s != c))
			{
				if (*s == 34 || *s == 39)
				{
					s++;
					while (*s)
					{
						s++;
						if (*s == 34 || *s == 39)
							break ;
					}
				}
				s++;
			}
		}
	}
	split[word] = NULL;
	return (split);
}
