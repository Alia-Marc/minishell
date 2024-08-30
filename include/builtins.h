/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:33:46 by alia              #+#    #+#             */
/*   Updated: 2024/08/30 18:52:58 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

# define CD_FILE "kimonOS: cd: %s: No such file or directory\n"
# define CD_HOME "kimonOS: cd: Home not set\n"
# define EXPORT_UNVALID "kimonOS: export: `%s': not a valid identifier\n"

/*			ENGAGE			*/
int			is_builtin(t_prompt *prompt);
int			is_non_print_builtin(t_prompt *prompt, t_exec *exec);
int			exec_builtin(t_prompt *prompt, t_exec *exec);

/*			MAKE ENV 		*/
char		**make_env(char **env);
char		**sort_env(char **env);

/*			PWD				*/
int			pwd_builtin(void);

/*			ECHO			*/
int			echo_builtin(t_prompt *prompt);

/*			ENV				*/
int			env_builtin(t_exec *exec);

/*			CD				*/
int			cd_builtin(t_prompt *prompt, t_exec *exec);

/*			EXPORT			*/
int			export_builtin(t_prompt *prompt, t_exec *exec);
int			check_var_exist(char **env, char *arg);
char		**add_to_env(char **env, char *arg);
char		**replace_from_env(char **env, char *arg);

/*			UNSET			*/
int			unset_builtin(t_prompt *prompt, t_exec *exec);


#endif