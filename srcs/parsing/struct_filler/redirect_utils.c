/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:23:59 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 19:07:17 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

t_file	*create_new_file(char *file, int mode)
{
	t_file	*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	if (!new_file)
		return (NULL);
	new_file->file = file;
	new_file->mode = mode;
	new_file->next = NULL;
	return (new_file);
}

t_file	*filelast(t_file *file)
{
	while (file)
	{
		if (!file->next)
			return (file);
		file = file->next;
	}
	return (file);
}

void	fileadd_back(t_file **file, t_file *new)
{
	t_file	*tmp;

	if (file)
	{
		if (*file)
		{
			tmp = filelast(*file);
			tmp->next = new;
		}
		else
			*file = new;
	}
}

int	count_quotes(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			count++;
		i++;
	}
	return (count);
}

int	is_in_redirect(char *s, int index, int max_index)
{
	while (s[index] && index < max_index)
	{
		skip_in_quotes(s, &index);
		if (ft_is_redirect(s[index]))
			return (1);
		if (s[index])
			index++;
	}
	return (0);
}

char	*ft_strdupnospace(char *str, int index)
{
	char	*dup;
	int		len;
	int		i;
	int		temp;

	len = 0;
	i = 0;
	temp = index;
	while (!ft_isspace(str[index]) && str[index] && !ft_is_metachar(str[index]))
	{
		index++;
		len++;
	}
	dup = ft_calloc(sizeof(char), (len + 1));
	if (dup == 0 || len == 0)
		return (NULL);
	while (!ft_isspace(str[temp]) && str[temp] && !ft_is_metachar(str[temp]))
	{
		dup[i] = str[temp];
		temp++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
