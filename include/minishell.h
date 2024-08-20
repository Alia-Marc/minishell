/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:27 by malia             #+#    #+#             */
/*   Updated: 2024/08/20 17:10:16 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int			g_signal;

typedef struct s_file
{
	char			*file;
	int				mode; //0 infile redir, 1 outfile red, 2 outfile redir append, 3 here_doc
	struct s_file	*next;
}					t_file;

typedef struct s_prompt
{
	t_file			*file;
	int				here_doc_fd;
	int				use_here_doc;
	//char			**here_doc;
	//int				len_here_doc;
	char			**cmd;
	int				len_cmd;
	char			*path;
	char			**env;
	int				error;
	struct s_prompt	*next;
}					t_prompt;

typedef struct s_exec
{
	char			**env;
	int				fd_in;
	int				fd_out;
	int				**pipefd;
//	int				here_docfd[2];
	int				exit;
	pid_t			pid;
	int				n_cmd;
}					t_exec;

#endif