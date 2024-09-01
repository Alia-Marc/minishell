/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:18:34 by malia             #+#    #+#             */
/*   Updated: 2024/09/01 23:41:46 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"

# define WRITE 1
# define READ 0
# define ERR_MALLOC "kimonOS: malloc failed\n"
# define NO_SUCH_FILE_OR_DIR "kimonOS: %s: No such file or directory\n"
# define COMMAND_NOT_FOUND "kimonOS: %s: command not found\n"

// get_path of a command
char		*get_path(char *cmd, char **env);
char		*get_line_value(char *name, char **env);

// Free Functions
void		free_file(t_file **file);
void		free_prompt(t_prompt **prompt);
void		exit_free_all(t_prompt *prompt, t_exec *exec, int code);

// Fake inits of t_files and t_prompts + small init of exec
void		fake_init(char **env, t_prompt *prompt);
t_file		*new_file(char *file, int mode);
t_file		*filelast(t_file *file);
void		fileadd_back(t_file **file, t_file *new);
t_prompt	*new_prompt(char *cmd, char *file0, char *file1, char **env, int file);
t_prompt	*promptlast(t_prompt *prompt);
void		promptadd_back(t_prompt **prompt, t_prompt *new);
t_exec		*init_exec(char **env, t_prompt *prompt);

// Handle files functions
int			open_close_redir(t_prompt *prompt);
int			open_file(t_prompt *prompt, char *file, int mode);
void		handle_fd(int fd, t_exec *exec, t_file *file);
void		assign_fds(t_prompt *prompt, t_exec *exec);
void		close_fds(t_exec *exec);

// Pipe handling
int			handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
int			last_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
void		do_child(int fd_in, t_exec *exec, int *pipe_fd, t_prompt *prompt);
void		exec_cmd(t_prompt *prompt, t_exec *exec);

// here_doc
void		write_heredoc(char *delimiter, int *fd);
void		use_here_doc(t_prompt *prompt);

// Error funtcions
void		error_handler(char *file, char *word, int code);

// Utils
int			wait_children(int pid);
int			len_prompt(t_prompt *prompt);

#endif