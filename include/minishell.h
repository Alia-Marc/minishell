/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:27 by malia             #+#    #+#             */
/*   Updated: 2024/09/11 15:50:00 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "error.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int			g_signal;

//mode file :
//(0)< = infile (1) > = outfile-trunc (2) >> = outfile-append (3) << = delimiter

typedef struct s_file
{
	char			*file;
	int				mode;
	struct s_file	*next;
}					t_file;

typedef struct s_prompt
{
	t_file			*file;
	char			**cmd;
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
	int				n_cmd;
	pid_t			*pid;
}					t_exec;

#endif
