/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:33:46 by alia              #+#    #+#             */
/*   Updated: 2024/09/09 23:33:23 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

# define CD_FILE "kimonOS: cd: %s: No such file or directory\n"
# define CD_HOME "kimonOS: cd: Home not set\n"
# define EXPORT_UNVALID "kimonOS: export: `%s': not a valid identifier\n"
# define EXIT_NON_NUMERIC "kimonOS: exit: %s: numeric agrument required\n"

/*			ENGAGE			*/
int			is_builtin(t_prompt *prompt);
int			is_modifying_env_builtin(t_prompt *prompt, t_exec *exec);
int			exec_builtin(t_prompt *prompt, t_exec *exec, int *pipe_fd);
int			exec_solo_builtin(t_prompt *prompt, t_exec *exec);

/*			INIT LOCAL ENV 		*/
char		**init_local_env(char **env);
char		**sort_env(char **env);

/*			PWD				*/
int			pwd_builtin(t_exec *exec);

/*			ECHO			*/
int			echo_builtin(t_prompt *prompt, t_exec *exec);

/*			ENV				*/
int			env_builtin(t_exec *exec);
int			check_char(char *str, char c);

/*			CD				*/
int			cd_builtin(t_prompt *prompt, t_exec *exec);

/*			EXPORT			*/
int			export_builtin(t_prompt *prompt, t_exec *exec);
int			check_var_exist(char **env, char *arg);
char		**add_to_env(char **env, char *arg);
char		**replace_from_env(char **env, char *arg);

/*			UNSET			*/
int			unset_builtin(t_prompt *prompt, t_exec *exec);

/*			EXIT			*/
int			exit_builtin(t_prompt *prompt, t_exec *exec);
int			exit_check_first_arg(char *str);

#endif