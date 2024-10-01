/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:22:01 by alia              #+#    #+#             */
/*   Updated: 2024/10/01 04:44:17 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	open_close_redir(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;
	t_file		*tmp_file;
	int			tmp_fd;

	tmp_prompt = prompt;
	if (!tmp_prompt)
		return (0);
	while (tmp_prompt)
	{
		tmp_file = tmp_prompt->file;
		while (tmp_file)
		{
			tmp_fd = open_file(tmp_prompt, tmp_file->file, tmp_file->mode);
			if (g_signal == SIGINT && hd_sigint_skip(prompt, exec))
				return (close(tmp_fd), 0);
			if (tmp_fd < 0)
			{
				tmp_prompt->error = 1;
				if (access(tmp_file->file, F_OK) == 0)
					ft_fdprintf(2, PERMISSION_DENIED, tmp_file->file);
				else
					ft_fdprintf(2, NO_SUCH_FILE_OR_DIR, tmp_file->file);
				break ;
			}
			//return (ft_fdprintf(2, NO_SUCH_FILE_OR_DIR, tmp_file->file), 0);//shoud be exiting and asking for a new prompt instead of continuing like now
			if (tmp_file->mode != 3)
				close(tmp_fd);
			tmp_file = tmp_file->next;
		}
		use_here_doc(tmp_prompt);
		tmp_prompt = tmp_prompt->next;
	}
	return (1);
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

int	open_file(t_prompt *prompt, char *file, int mode)
{
	int	fd;
	int	pipe_fd[2];

	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY, 0644);
	if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (mode == 3)
	{
		init_sig(SIGINT, &handle_sigint_hd);
		if (!isatty(prompt->here_doc_fd) && prompt->here_doc_fd > 2)
			close(prompt->here_doc_fd);
		if (pipe(pipe_fd) == -1)
			exit(0);
		write_heredoc(file, pipe_fd);
		close(pipe_fd[WRITE]);
		prompt->here_doc_fd = pipe_fd[READ];
		return (pipe_fd[READ]);
	}
	return (fd);
}

void	assign_fds(t_prompt *prompt, t_exec *exec)
{
	t_file	*tmp_file;
	int		tmp_fd;

	tmp_file = prompt->file;
	close_fds(exec);
	while (tmp_file)
	{
		if (tmp_file->mode != 3)
		{
			tmp_fd = open_file(prompt, tmp_file->file, tmp_file->mode);
			handle_fd(tmp_fd, exec, tmp_file);
		}
		tmp_file = tmp_file->next;
	}
	if (prompt->use_here_doc)
	{
		if (exec->fd_in > 2)
			close(exec->fd_in);
		exec->fd_in = prompt->here_doc_fd;
	}
	else if (prompt->here_doc_fd > 2)
		close(prompt->here_doc_fd);
}
