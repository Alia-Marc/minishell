/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:18:34 by malia             #+#    #+#             */
/*   Updated: 2024/07/25 15:59:04 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

char		*get_path(char *cmd, char **env);
char		*get_line_value(char *name, char **env);


void		fake_init(char **env, t_prompt *prompt);
t_file		*new_file(char *file, int mode);
t_file		*filelast(t_file *file);
void		fileadd_back(t_file **file, t_file *new);
t_prompt	*new_prompt(char *cmd0, char *cmd1, char *file0, char *file1, char **env);
t_prompt	*promptlast(t_prompt *prompt);
void		promptadd_back(t_prompt **prompt, t_prompt *new);

// Free Functions
void		free_file(t_file **file);
void		free_prompt(t_prompt **prompt);

#endif