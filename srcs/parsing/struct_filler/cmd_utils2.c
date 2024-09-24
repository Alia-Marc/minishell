/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:41 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/24 17:22:38 by emfourni         ###   ########.fr       */
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
		index++;;
	}
	free(str);
}

static	char	*ft_worddup(char *str, char c)
{
	size_t	index;
	char	*dst;

	index = 0;
	while ((str[index] && str[index] != c)
			|| (str[index] == c && is_char_in_quotes(str, index)))
		index++;
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while ((str[index] && str[index] != c)
			|| (str[index] == c && is_char_in_quotes(str, index)))
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	**split_cmd_pipe(char *s, char c)
{
	int		word;
	char	**split;

	if (!s)
		return (NULL);
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
			split[word] = ft_worddup(s, c);
			if (!split[word])
				return (free_cmd(split), NULL);
			word++;
			while (*s && *s != c)
			{
				if (*s && (*s == 34 || *s == 39))
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
