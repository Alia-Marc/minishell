/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:27:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/16 18:25:54 by emfourni         ###   ########.fr       */
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
					|| (within_single_quote2(str, index)
					|| within_double_quote2(str, index)))
				index++;
		}
	}
	return (count);
}

static get_first_quote(char *str)
{
	int	index;
	int	first_pos;


	index = 0;
	first_pos = 0;
	while (str[index])
	{
		if (str[index] == 34 || str[index] == 39)
			first_pos = 0;
		index++;
	}
}

static get_first_quote(char *str)
{

}
static	char	*ft_worddup(char *str, char c)
{
	int		index;
	int		first_quote;
	int		last_quote;
	char	*dst;

	index = 0;
	first_quote = get_first_quote(str);
	last_quote = get_last_quote(str);
	while ((str[index] && str[index] != c)
			|| (within_single_quote2(str, index) || within_double_quote2(str, index)))
			index++;
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while ((str[index] && str[index] != c)
			|| (within_single_quote2(str, index) || within_double_quote2(str, index)))
	{
			dst[index] = str[index];
			index++;
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
