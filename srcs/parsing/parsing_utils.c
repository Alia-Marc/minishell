/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/13 14:59:18 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/parsing.h"

t_prompt	*prompt_init(t_prompt *prompt)
{
	prompt = malloc(sizeof(t_prompt));
	if (!prompt)
		return (NULL);
    prompt->file = NULL;
	prompt->cmd = NULL;
	prompt->use_heredoc = 0;
	// prompt->env = make_env();
	// prompt->path = getpath(prompt->cmd, prompt->env);
    prompt->next = NULL;
	return (prompt);
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

void	free_prompt(t_prompt **prompt)
{
	t_prompt	*tmp;

	if (!prompt)
		return ;
	while ((*prompt)->next != NULL)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
		free_cmd((*prompt)->cmd);
		free(*prompt);
		*prompt = tmp;
	}
}

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
	return (false);
}
