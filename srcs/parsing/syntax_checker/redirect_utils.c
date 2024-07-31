/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:54:33 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/31 17:13:36 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

void	free_file(t_file **file)
{
	t_file	*tmp;

	if (!file)
		return ;
	while (*file)
	{
		tmp = (*file)->next;
		free(*file);
		*file = tmp;
	}
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
	dup = (char *)malloc((len + 2) * sizeof(char));
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
