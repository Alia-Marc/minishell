/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/09 17:18:51 by emfourni         ###   ########.fr       */
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
	// prompt->cmd = NULL;
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
	while (*prompt)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
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

// int	ft_onlywhitespace(char *str, int len)
// {
// 	while (len > 0)
// 	{
// 		if (!ft_isspace(str[len]))
// 			return (0);
// 		len--;
// 	}
// 	return (1);
// }
