/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:41:54 by marc              #+#    #+#             */
/*   Updated: 2024/08/30 01:35:13 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static char	*join_var_value(char *var, char *value)
{
	char	*tab;

	tab = ft_strjoin(var, value);
	if (!tab)
		return (free(value), NULL);
	free(value);
	return (tab);
}

static void	update_env_tab(t_exec *exec, char *tab, int *flag, int i)
{
	free(exec->env[i]);
	exec->env[i] = tab;
	*flag = 1;
}

static void	update_old_and_newpwd(t_exec *exec, char *new_pwd, char *old_pwd)
{
	int	i;
	int	new_flag;
	int	old_flag;

	i = 0;
	new_flag = 0;
	old_flag = 0;
	while (exec->env && exec->env[i])
	{
		if (ft_strncmp(exec->env[i], "PWD=", 4) == 0)
			update_env_tab(exec, new_pwd, &new_flag, i);
		if (ft_strncmp(exec->env[i], "OLDPWD=", 7) == 0)
			update_env_tab(exec, old_pwd, &old_flag, i);
		i++;
	}
	if (!new_flag)
	{
		exec->env = add_to_env(exec->env, new_pwd);
		free(new_pwd);
	}
	if (!old_flag)
	{
		exec->env = add_to_env(exec->env, old_pwd);
		free(old_pwd);
	}
}

static int	cd_home_or_path(t_prompt *prompt, t_exec *exec,
		char *new_pwd, char *old_pwd)
{
	if (prompt->cmd[1] == NULL && ft_strlen2(prompt->cmd) == 1)
	{
		new_pwd = ft_strdup(get_line_value("HOME", exec->env));
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, CD_HOME), 1);
		if (chdir(new_pwd) != 0)
			return (free(old_pwd), free(new_pwd), ft_fdprintf(2, CD_HOME), 1);
		new_pwd = join_var_value("PWD=", new_pwd);
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, ERR_MALLOC), 1);
		update_old_and_newpwd(exec, new_pwd, old_pwd);
	}
	else
	{
		if (chdir(prompt->cmd[1]) != 0)
			return (free(old_pwd), ft_fdprintf(2, CD_FILE, prompt->cmd[1]), 1);
		new_pwd = getcwd(0, 0);
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, ERR_MALLOC), 1);
		new_pwd = join_var_value("PWD=", new_pwd);
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, ERR_MALLOC), 1);
		update_old_and_newpwd(exec, new_pwd, old_pwd);
	}
	return (0);
}

int	cd_builtin(t_prompt *prompt, t_exec *exec)
{
	char	*old_pwd;
	char	*new_pwd;

	new_pwd = NULL;
	if (prompt->cmd[1] != NULL && prompt->cmd[2] != NULL)
		return (ft_fdprintf(2, "kimonOS: cd: too many arguments\n"), 1);
	old_pwd = getcwd(0, 0);
	if (!old_pwd)
		return (ft_fdprintf(2, ERR_MALLOC), 1);
	old_pwd = join_var_value("OLDPWD=", old_pwd);
	if (!old_pwd)
		return (ft_fdprintf(2, ERR_MALLOC), 1);
	return (cd_home_or_path(prompt, exec, new_pwd, old_pwd));
}
