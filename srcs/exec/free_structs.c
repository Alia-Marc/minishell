/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:49:11 by marc              #+#    #+#             */
/*   Updated: 2024/08/19 23:50:08 by marc             ###   ########.fr       */
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
