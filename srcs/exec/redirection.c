/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:22:01 by alia              #+#    #+#             */
/*   Updated: 2024/07/26 00:55:42 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	open_redir_files(t_prompt *prompt)
{
	t_prompt	*tmp_prompt;
	t_file		*tmp_file;
	int			tmp_fd;

	tmp_prompt = prompt;
	if (!tmp_prompt)
		return ;
	while (tmp_prompt)
	{
		tmp_file = tmp_prompt->file;
		while (tmp_file)
		{
			tmp_fd = open_file(tmp_file->file, tmp_file->mode);
			//ft_printf("%s\n", tmp_file->file);
			if (tmp_fd < 0)
				error_handler(tmp_file->file, ": ", 0);
			if (tmp_fd > 0)
				close(tmp_fd);
			tmp_file = tmp_file->next;
		}
		tmp_prompt = tmp_prompt->next;
	}
}

int	open_file(char *file, int mode)
{
	int	fd;
	
	fd = 0;
	if (mode == 1)
		fd = open(file, O_RDONLY, 0644);
	if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 3)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}
