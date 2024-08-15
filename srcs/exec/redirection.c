/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:22:01 by alia              #+#    #+#             */
/*   Updated: 2024/08/15 04:55:56 by marc             ###   ########.fr       */
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
				error_handler(tmp_file->file, ": ", 0); //shoud be exiting and return a new prompt instead of continuing like now
			close(tmp_fd);
			tmp_file = tmp_file->next;
		}
		tmp_prompt = tmp_prompt->next;
	}
}

void	handle_fd(int fd, t_exec *exec, t_file *file)
{
	if (exec->fd_in != 0 && file->mode == 0)
		close(exec->fd_in);
	else if (exec->fd_out != 1 && (file->mode == 1 || file->mode == 2))
		close(exec->fd_out);
	if (file->mode == 0)
		exec->fd_in = fd;
	else if (file->mode == 1 || file->mode == 2)
		exec->fd_out = fd;
}

int	open_file(char *file, int mode)
{
	int	fd;
	
	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY, 0644);
	if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

void	assign_fds(t_prompt *prompt, t_exec *exec)
{
	t_file	*tmp_file;
	int		tmp_fd;

	tmp_file = prompt->file;
	while (tmp_file)
	{
		tmp_fd = open_file(tmp_file->file, tmp_file->mode);
		handle_fd(tmp_fd, exec, tmp_file);
		tmp_file = tmp_file->next;
	}
}
