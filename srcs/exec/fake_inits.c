/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:07:08 by alia              #+#    #+#             */
/*   Updated: 2024/08/22 17:07:55 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void fake_init(char **env, t_prompt *prompt)
{
	//prompt->file->file = (char * )malloc(sizeof(char) * 4);
	prompt->cmd = ft_split("cat", ' ');
	//ft_printf("%s\n%s\n", prompt->cmd[0], prompt->cmd[1]);
	//prompt->cmd = NULL;
	prompt->env = env;
	prompt->path = get_path(prompt->cmd[0], env);
	//ft_printf("%s\n", prompt->path);
	//prompt->path = NULL;
	prompt->next = NULL;
	prompt->file = NULL;
	prompt->here_doc_fd = -2;
	//free(env);
}

t_exec	*init_exec(char **env, t_prompt *prompt)
{
	t_exec	*exec;
	
	exec = (t_exec *)malloc(sizeof(t_exec));
	if (!exec)
		return (NULL);
	exec->env = env;
	exec->fd_in = 0;
	exec->fd_out = 1;
	exec->n_cmd = len_prompt(prompt);
	return (exec);
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
	new_prompt->env = env;
	new_prompt->path = get_path(new_prompt->cmd[0], env);
	new_prompt->here_doc_fd = -2;
	new_prompt->next = NULL;

	if (file)
	{
		new_prompt->file = new_file(file0, 0);
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
