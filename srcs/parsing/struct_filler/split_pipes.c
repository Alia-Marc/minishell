/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:41 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/10 13:22:10 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static void	skipped_single_quotes_word(char *str, int *i, int *j, int *skipped)
{
	if (str[*i] == 39)
	{
		*skipped = 1;
		(*i)++;
		(*j)++;
		while (str[*i])
		{
			if (str[*i] == 39)
			{
				(*i)++;
				break ;
			}
			(*i)++;
			(*j)++;
		}
	}
}

int	skipped_quotes_worddup(char *str, int *i, int *j)
{
	int	skipped;

	skipped = 0;
	if (str[*i] == 34)
	{
		skipped = 1;
		(*i)++;
		(*j)++;
		while (str[*i])
		{
			if (str[*i] == 34)
			{
				(*i)++;
				break ;
			}
			(*i)++;
			(*j)++;
		}
	}
	skipped_single_quotes_word(str, i, j, &skipped);
	return (skipped);
}


int	ft_countword(char *str, char c)
{
	int (index) = 0;
	int (count) = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (skipped_quotes(str, &index))
		{
			if (!str[index] || str[index] == c)
				count++;
			continue ;
		}
		while (str[index] && str[index] == c)
			index++;
		if (str[index] && str[index] != c)
		{
			count++;
			while (str[index] && str[index] != c)
				index++;
		}
	}
	return (count);
}

static	char	*ft_worddup(char *str, int i, char c)
{
	char	*dst;

	int (index) = 0;
	while (str[i] && str[i] != c)
	{
		if (skipped_quotes(str, &i))
		{
			index = i;
			continue ;
		}
		i++;
		index++;
	}
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (NULL);
	i -= index;
	index = 0;
	while (str[i] && str[i] != c)
	{
		if (skipped_copy_quotes(str, dst, &i, &index))
			continue ;
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

	int (n_pipes) = ft_countword(s, c);
	int (word) = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (n_pipes + 1));
	if (!split)
		return (NULL);
	while (word < n_pipes)
	{
		split[word] = ft_worddup(s, i, c);
		if (!split[word])
			return (ft_free_tab(split), NULL);
		i += ft_strlen(split[word]) + 1;
		word++;
	}
	split[word] = NULL;
	return (split);
}
