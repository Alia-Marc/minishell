/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:45:21 by marc              #+#    #+#             */
/*   Updated: 2024/09/24 17:44:05 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	write_heredoc(char *delimiter, int *fd)
{
	char	*line;
	size_t	del_len;

	del_len = ft_strlen(delimiter);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			perror("");
			break ;
		}
		if (!ft_strncmp(line, delimiter, del_len) && line[del_len] == '\n')
			break ;
		ft_putstr_fd(line, fd[WRITE]);
		free(line);
	}
	free(line);
}

void	use_here_doc(t_prompt *prompt)
{
	t_file	*tmp_file;
	int		mode;

	if (prompt->error)
		return ;
	tmp_file = prompt->file;
	mode = -1;
	while (tmp_file)
	{
		if (tmp_file->mode == 0 || tmp_file->mode == 3)
			mode = tmp_file->mode;
		tmp_file = tmp_file->next;
	}
	prompt->use_here_doc = 0;
	if (mode == 3)
		prompt->use_here_doc = 1;
}

void	close_unused_next_hd(t_prompt *prompt)
{
	t_prompt	*tmp_prompt;

	tmp_prompt = prompt->next;
	while (tmp_prompt)
	{
		if (!isatty(tmp_prompt->here_doc_fd) && tmp_prompt->here_doc_fd > 2)
			close (tmp_prompt->here_doc_fd);
		tmp_prompt = tmp_prompt->next;
	}
}

// int	here_doc(char **av, char **env)
// {
// 	int		pipe_fd1[2];
// 	int		pipe_fd2[2];
// 	pid_t	pid;	

// 	if (pipe(pipe_fd1) == -1)
// 		exit(0);
// 	write_heredoc(av[2], pipe_fd1);
// 	close(pipe_fd1[WRITE]);
// 	if (pipe(pipe_fd2) == -1)
// 		exit(0);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);
// 	if (pid == 0)
// 	{
// 		do_child(pipe_fd1[READ], pipe_fd2, 0);
// 		exec(av[3], env);
// 		exit(0);
// 	}
// 	else
// 	{
// 		close(pipe_fd2[WRITE]);
// 		close(pipe_fd1[READ]);
// 		return (pipe_fd2[READ]);
// 	}
// }

// void	write_heredoc(char *delimiter, int *fd)
// {
// 	char	*line;
// 	size_t	del_len;

// 	del_len = ft_strlen(delimiter);
// 	while (1)
// 	{
// 		ft_printf("> ");
// 		line = get_next_line(STDIN_FILENO);
// 		if (!line)
// 		{
// 			perror("");
// 			break ;
// 		}
// 		if (!ft_strncmp(line, delimiter, del_len) && line[del_len] == '\n')
// 			break ;
// 		ft_putstr_fd(line, fd[WRITE]);
// 		free(line);
// 	}
// 	free(line);
// }
