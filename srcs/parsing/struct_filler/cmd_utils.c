/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/17 17:44:40 by emilefourni      ###   ########.fr       */
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

static int  ft_countlen(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while ((str[index] && str[index] != c) 
			|| (str[index] == c && is_char_in_quotes(str, index)))
		index++;
	return (index - 1);
}

static	char	*ft_worddup(char *str, char c)
{
	int		index;
	int		first_pos;
	int		last_pos;
    int     i;
	char	*dst;

	index = 0;
	first_pos = 0;
	last_pos = 0;
	while ((str[index] && str[index] != c) || (str[index] == c && is_char_in_quotes(str, index)))
	{
			if ((str[index] == 34 || str[index] == 39) && (index == 0))
			{
				first_pos = index;
				index++;
			}
			else if ((str[index] == 34 || str[index] == 39) && (index == ft_countlen(str, c)))
			{
				last_pos = index;
				index++;
			}
			else
				index++;
	}
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	index = 0;
    i = 0;
	while ((str[index] && str[index] != c) || (str[index] == c && is_char_in_quotes(str, index)))
	{
			if ((str[index] == 34 || str[index] == 39) && (index == first_pos || index == last_pos))
				index++;
			else
			{
				dst[i] = str[index];
				index++;
                i++;
			}
	}
	dst[index] = '\0';
	return (dst);
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

char	**split_cmd(char *s, char c)
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
			if (!ft_is_redirect(*s))
			{
				split[word] = ft_worddup(s, c);
				if (!split[word])
					return (free_cmd(split), NULL);
				word++;
			}
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
