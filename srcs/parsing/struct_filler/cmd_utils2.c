/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:59:41 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/30 03:01:02 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int is_char_in_quotes2(char *str, int index)
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
	int		(i) = 0;
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
		{
			s++;
			i++;
		}
		if (*s && *s != c)
		{
			split[word] = ft_worddup(s, c);
			if (!split[word])
				return (free_cmd(split), NULL);
			word++;
			while (*s && (*s != c || (*s == c && is_char_in_quotes(s, i))))
			{
				s++;
				i++;
			}
		}
	}
	split[word] = NULL;
	return (split);
}

int main(int argc, char *argv[])
{
	char **split;
	int	index;
	int nb_words;

	(void) argc;
	
	index = 0;
	split = split_cmd_pipe(argv[1], '|');
	nb_words = ft_countword(argv[1], '|');
	while (split[index])
		printf("word : %s\n %d\n", split[index++], nb_words);
	free_cmd(split);
	return 0;
}