/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:18:34 by malia             #+#    #+#             */
/*   Updated: 2024/10/09 13:49:54 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"
# include "minishell_signal.h"

# define WRITE 1
# define READ 0
# define ERR_MALLOC "kimonOS: malloc failed\n"
# define NO_SUCH_FILE_OR_DIR "kimonOS: %s: No such file or directory\n"
# define PERMISSION_DENIED "kimonOS: %s: Permission denied\n"
# define COMMAND_NOT_FOUND "kimonOS: %s: command not found\n"
# define CLOSED_HD_BY_EOF "\nkimonOS: warning: here-document delimited \
by end-of-file (wanted `%s')\n"

// get_path of a command
char		*get_path(char *cmd, char **env);
char		*get_line_value(char *name, char **env);

// Free Functions
void		free_file(t_file **file);
void		free_prompt(t_prompt **prompt);
void		exit_free_all(t_prompt *prompt, t_exec *exec, int code);

// Init Exec
t_exec		*init_exec(char **env);
void		reset_exec(t_exec *exec);

// Handle files functions
int			open_close_redir(t_prompt *prompt, t_exec *exec);
int			open_file(t_prompt *prompt, t_exec *exec, t_file *file);
void		handle_fd(int fd, t_exec *exec, t_file *file);
void		assign_fds(t_prompt *prompt, t_exec *exec);
void		close_fds(t_exec *exec);

// Pipe handling
int			handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
int			last_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
void		do_child(int fd_in, t_exec *exec, int *pipe_fd, t_prompt *prompt);
void		exec_cmd(t_prompt *prompt, t_exec *exec);

// here_doc
void		write_heredoc(t_exec *exec, char *delimiter, int *fd);
void		use_here_doc(t_prompt *prompt);
void		close_unused_next_hd(t_prompt *prompt, int next);

// Error funtcions
void		error_handler(char *file, char *word, int code);

// Utils
int			wait_children(t_exec *exec, int pid);
int			len_prompt(t_prompt *prompt);

void		exec_prompt(t_prompt *prompt, t_exec *exec);

#endif
