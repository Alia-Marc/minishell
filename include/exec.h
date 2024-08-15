/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:18:34 by malia             #+#    #+#             */
/*   Updated: 2024/08/15 05:18:21 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define WRITE 1
# define READ 0

// get_path of a command
char		*get_path(char *cmd, char **env);
char		*get_line_value(char *name, char **env);

// Free Functions
void		free_file(t_file **file);
void		free_prompt(t_prompt **prompt);

// Fake inits of t_files and t_prompts + small init of exec
void		fake_init(char **env, t_prompt *prompt);
t_file		*new_file(char *file, int mode);
t_file		*filelast(t_file *file);
void		fileadd_back(t_file **file, t_file *new);
t_prompt	*new_prompt(char *cmd, char *file0, char *file1, char **env, int file);
t_prompt	*promptlast(t_prompt *prompt);
void		promptadd_back(t_prompt **prompt, t_prompt *new);
t_exec		*init_exec(char **env, t_prompt *prompt);

// Open files functions
void		open_redir_files(t_prompt *prompt);
int			open_file(char *file, int mode);
void		handle_fd(int fd, t_exec *exec, t_file *file);
void		assign_fds(t_prompt *prompt, t_exec *exec);

// Pipe handling
int			handle_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
int			last_pipe(t_prompt *prompt, t_exec *exec, int fd_infile);
void		do_child(int fd_infile, int fd_outfile, int *pipe_fd);
void		exec_cmd(t_prompt *prompt, t_exec *exec);

// Error funtcions
void		error_handler(char *file, char *word, int code);

// Utils
int			wait_children(int pid);
int			len_prompt(t_prompt *prompt);

#endif