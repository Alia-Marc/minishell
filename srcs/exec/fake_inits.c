/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:07:08 by alia              #+#    #+#             */
/*   Updated: 2024/09/16 13:44:07 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void fake_init(char **env, t_prompt *prompt)
{
	prompt->cmd = ft_split("", ' ');
	prompt->path = get_path(prompt->cmd[0], env);
	prompt->next = NULL;
	prompt->file = NULL;
	prompt->here_doc_fd = -2;
}

t_file	*new_file(char *file, int mode)
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

t_prompt	*new_prompt(char *cmd, char *file0, char *file1, char **env, int file)
{
	t_prompt	*new_prompt;

	new_prompt = (t_prompt *)malloc(sizeof(t_prompt));
	new_prompt->cmd = ft_split(cmd, ' ');
	new_prompt->path = get_path(new_prompt->cmd[0], env);
	new_prompt->here_doc_fd = -2;
	new_prompt->next = NULL;

	if (file)
	{
		new_prompt->file = new_file(file0, 1);
		fileadd_back(&new_prompt->file, new_file(file1, 1));
	}
	else
		new_prompt->file = NULL;
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
