/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:18:34 by malia             #+#    #+#             */
/*   Updated: 2024/07/26 00:55:18 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

// get_path of a command
char		*get_path(char *cmd, char **env);
char		*get_line_value(char *name, char **env);

// Free Functions
void		free_file(t_file **file);
void		free_prompt(t_prompt **prompt);

// Fake inits of t_files and t_prompts
void		fake_init(char **env, t_prompt *prompt);
t_file		*new_file(char *file, int mode);
t_file		*filelast(t_file *file);
void		fileadd_back(t_file **file, t_file *new);
t_prompt	*new_prompt(char *cmd0, char *cmd1, char *file0, char *file1, char **env);
t_prompt	*promptlast(t_prompt *prompt);
void		promptadd_back(t_prompt **prompt, t_prompt *new);

// Open functions
void		open_redir_files(t_prompt *prompt);
int			open_file(char *file, int mode);

// Error funtcions
void		error_handler(char *file, char *word, int code);

#endif