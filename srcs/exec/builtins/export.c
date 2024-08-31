/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:12:54 by alia              #+#    #+#             */
/*   Updated: 2024/08/31 02:56:00 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static int	no_args(t_exec *exec)
{
	int	i;
	int	j;
	int	first;

	i = 0;
	while (exec->env && exec->env[i])
	{
		write(exec->fd_out, "declare -x ", 11);
		j = 0;
		first = 0;
		while (exec->env[i][j])
		{
			write(exec->fd_out, &exec->env[i][j], 1);
			if ((exec->env[i][j] == '=' && !first)
				|| (exec->env[i][j + 1] == '\0' && first))
			{
				write(exec->fd_out, "\"", 1);
				first = 1;
			}
			j++;
		}
		i++;
		write(exec->fd_out, "\n", 1);
	}
	return (0);
}

static int	is_var_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (((i == 0 && !ft_isalpha(str[i]))
				|| !ft_isalnum(str[i])) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	**replace_from_env(char **env, char *arg)
{
	int		len_var;
	int		i;
	char	*tmp;

	len_var = ft_strlen_until_char(arg, '=');
	i = 0;
	while (env && env[i] && ft_strncmp(env[i], arg, len_var) != 0)
		i++;
	tmp = env[i];
	env[i] = ft_strdup(arg);
	if (!env[i])
	{
		env[i] = tmp;
		return (env);
	}
	free(tmp);
	return (env);
}

char	**add_to_env(char **env, char *arg)
{
	char	**new_env;
	int		i;

	if (check_var_exist(env, arg))
		return (replace_from_env(env, arg));
	i = ft_strlen2(env) + 1;
	new_env = ft_calloc(i + 1, sizeof(char *));
	if (!new_env)
		return ((void)ft_fdprintf(2, ERR_MALLOC), env);
	new_env[i] = NULL;
	i = 0;
	while (env && env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i] = ft_strdup(arg);
	if (!new_env[i])
		ft_fdprintf(2, ERR_MALLOC);
	free(env);
	return (sort_env(new_env));
}

int	export_builtin(t_prompt *prompt, t_exec *exec)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (prompt->cmd[1] == NULL && ft_strlen2(prompt->cmd) == 1)
		return (no_args(exec));
	while (prompt->cmd[i])
	{
		if (is_var_valid(prompt->cmd[i]))
			exec->env = add_to_env(exec->env, prompt->cmd[i]);
		else
		{
			ft_fdprintf(2, EXPORT_UNVALID, prompt->cmd[i]);
			error = 1;
		}
		i++;
	}
	return (error);
}
