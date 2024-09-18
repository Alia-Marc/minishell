/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:07:45 by alia              #+#    #+#             */
/*   Updated: 2024/08/30 19:23:53 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static int	is_var_valid(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

static char	**remove_from_env(char **env, int j)
{
	int		i;
	int		k;
	char	**new_env;

	i = 0;
	k = 0;
	new_env = ft_calloc(ft_strlen2(env), sizeof(char *));
	if (!new_env)
		return (env);
	while (env[k])
	{
		if (k == j)
		{
			k++;
			continue ;
		}
		new_env[i] = env[k];
		i++;
		k++;
	}
	free(env[j]);
	free(env);
	return (new_env);
}

int	unset_builtin(t_prompt *prompt, t_exec *exec)
{
	int	i;
	int	j;
	int	len_arg;

	i = 1;
	while (prompt->cmd[i])
	{
		j = 0;
		len_arg = ft_strlen(prompt->cmd[i]);
		while (exec->env && exec->env[j]
			&& !(ft_strncmp(exec->env[j], prompt->cmd[i], len_arg) == 0
				&& (exec->env[j][len_arg] == '=' || !exec->env[j][len_arg])))
			j++;
		if (exec->env[j] && is_var_valid(prompt->cmd[i]))
			exec->env = remove_from_env(exec->env, j);
		i++;
	}
	return (0);
}
