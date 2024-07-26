/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:27 by malia             #+#    #+#             */
/*   Updated: 2024/07/26 12:15:21 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include "parsing.h"
#include "error.h"
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

extern int			g_signal;

typedef struct s_file
{
	char			*file;
	int				mode; // (0) = int file   (1) > = redirection outfile en trunc      (2) >> = redirection append
	struct s_file	*next;
}					t_file;

typedef struct s_prompt
{
	t_file			*file;
	char			**here_doc;
	int				len_here_doc;
	char			**cmd;
	int				len_cmd;
	int				use_heredoc;
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
	int				here_docfd[2];
	int				exit;
	pid_t			*pid;
}					t_exec;


#endif
