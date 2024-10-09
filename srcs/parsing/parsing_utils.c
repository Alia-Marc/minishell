/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 13:25:54 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parsing.h"

t_prompt	*prompt_init(void)
{
	t_prompt	*new_prompt;

	new_prompt = malloc(sizeof(t_prompt));
	if (!new_prompt)
		return (NULL);
	new_prompt->file = NULL;
	new_prompt->cmd = NULL;
	new_prompt->use_here_doc = 0;
	new_prompt->here_doc_fd = -2;
	new_prompt->error = 0;
	new_prompt->path = NULL;
	new_prompt->next = NULL;
	return (new_prompt);
}

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

// void	free_prompt(t_prompt **prompt)
// {
// 	t_prompt	*tmp;

// 	if (!prompt)
// 		return ;
// 	while ((*prompt)->next != NULL)
// 	{
// 		tmp = (*prompt)->next;
// 		free_file(&(*prompt)->file);
// 		free_cmd((*prompt)->cmd);
// 		free(*prompt);
// 		*prompt = tmp;
// 	}
// }

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
	return (false);
}
