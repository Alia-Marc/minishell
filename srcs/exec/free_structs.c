/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:49:11 by marc              #+#    #+#             */
/*   Updated: 2024/08/22 16:43:08 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"


void	free_prompt(t_prompt **prompt)
{
	t_prompt	*tmp;

	if (!prompt)
		return ;
	while (*prompt)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
		ft_free_tab((*prompt)->cmd);
		if ((*prompt)->path)
			free((*prompt)->path);
		free(*prompt);
		*prompt = tmp;
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

void	exit_free_all(t_prompt *prompt, t_exec *exec)
{
	free_prompt(&prompt);
	free(exec);
	exit(errno);
}
