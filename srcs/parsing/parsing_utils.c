/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by emfourni          #+#    #+#             */
/*   Updated: 2024/08/24 17:33:17 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parsing.h"

t_prompt	*promptlast(t_prompt *prompt)
{
	while (prompt)
	{
		if (!prompt->next)
			return (prompt);
		prompt = prompt->next;
	}
	return (prompt);
}

void	promptadd_back(t_prompt **prompt, t_prompt *new)
{
	t_prompt	*tmp;

	if (prompt)
	{
		if (*prompt)
		{
			tmp = promptlast(*prompt);
			tmp->next = new;
		}
		else
			*prompt = new;
	}
}

void	free_prompt(t_prompt **prompt)
{
	t_prompt	*tmp;

	if (!prompt)
		return ;
	while (*prompt)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
		free(*prompt);
		*prompt = tmp;
	}
}
