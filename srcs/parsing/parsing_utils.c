/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/31 16:31:47 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_prompt	*new_prompt(char *cmd0, char *cmd1, char *file0, char *file1, char **env)
{
	t_prompt	*new_prompt;

	new_prompt = (t_prompt *)malloc(sizeof(t_prompt));
	new_prompt->cmd = (char **)malloc(sizeof(char *) * 3);
	new_prompt->cmd[0] = cmd0;
	new_prompt->cmd[1] = cmd1;
	new_prompt->cmd[2] = "\0";
	new_prompt->env = env;
	// new_prompt->path = get_path(new_prompt->cmd[0], env);
	new_prompt->next = NULL;
	new_prompt->file = create_new_file(file0, 0);
	fileadd_back(&new_prompt->file, create_new_file(file1, 1));
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

void	free_prompt(t_prompt **prompt)
{
	t_prompt	*tmp;

	if (!prompt)
		return ;
	while (*prompt)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
		free((*prompt)->cmd);
		free((*prompt)->path);
		free(*prompt);
		*prompt = tmp;
	}
}
