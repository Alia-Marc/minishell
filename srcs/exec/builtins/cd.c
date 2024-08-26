/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:41:54 by marc              #+#    #+#             */
/*   Updated: 2024/08/26 16:37:01 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static void	update_old_and_newpwd(t_exec *exec, char *new_pwd, char *old_pwd)
{
	int	i;

	i = 0;
	while (exec->env && exec->env[i])
	{
		if (ft_strncmp(exec->env[i], "PWD=", 4) == 0)
		{
			free(exec->env[i]);
			exec->env[i] = ft_strjoin("PWD=", new_pwd);
			free(new_pwd);
			//ft_printf("PWD=%s found and replaced\n", exec->env[i]);
		}
		if (ft_strncmp(exec->env[i], "OLDPWD=", 7) == 0)
		{
			free(exec->env[i]);
			exec->env[i] = ft_strjoin("OLDPWD=", old_pwd);
			free(old_pwd);
			//ft_printf("OLDPWD=%s found and replaced\n", exec->env[i]);
		}
		i++;
	}
	// Doit gérer le cas où OLDPWD n'éxiste pas
}

int	cd_builtin(t_prompt *prompt, t_exec *exec)
{
	char	*old_pwd;
	char	*new_pwd;

	if (prompt->cmd[1] != NULL && prompt->cmd[2] != NULL)
		return (ft_fdprintf(2, "kimonOS: cd: too many arguments\n"), 1);
	old_pwd = ft_strdup(get_line_value("PWD", exec->env));
	if (!old_pwd)
		return (ft_fdprintf(2, "kimonOS: malloc failed\n"), 1);
	if (prompt->cmd[1] == NULL && ft_strlen2(prompt->cmd) == 1)
	{
		new_pwd = ft_strdup(get_line_value("HOME", exec->env));
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, "kimonOS: cd: Home not set\n"), 1);
		if (chdir(new_pwd) != 0)
			return (free(old_pwd), ft_fdprintf(2, "kimonOS: cd: Home not set\n"), 1);
		//ft_fdprintf(2, "home cd");
		update_old_and_newpwd(exec, new_pwd, old_pwd);
	}
	else
	{
		if (chdir(prompt->cmd[1]) != 0)
			return (free(old_pwd), ft_fdprintf(2, "kimonOS: cd: %s: No such file or directory\n", prompt->cmd[1]), 1);
		new_pwd = getcwd(0, 0);
		if (!new_pwd)
			return (free(old_pwd), ft_fdprintf(2, "kimonOS: malloc failed\n"), 1);
		//ft_fdprintf(2, "eh ouais");
		update_old_and_newpwd(exec, new_pwd, old_pwd);
	}
	return (errno);
}
