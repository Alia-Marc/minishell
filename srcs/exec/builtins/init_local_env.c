/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_local_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:02:50 by marc              #+#    #+#             */
/*   Updated: 2024/09/10 03:05:18 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static int	find_shlvl(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0 && env[i][6])
			return (ft_atoi(&env[i][6]));
		i++;
	}
	return (0);
}

static char	**modify_shlvl(char **new_env)
{
	int		shlvl_value;
	char	*value;
	char	*new_shlvl;

	shlvl_value = find_shlvl(new_env);
	if (shlvl_value <= 0)
		return (add_to_env(new_env, "SHLVL=1"));
	value = ft_itoa(shlvl_value + 1);
	if (!value)
		return (new_env);
	new_shlvl = ft_strjoin("SHLVL=", value);
	if (!new_shlvl)
		return (free(value), new_env);
	new_env = add_to_env(new_env, new_shlvl);
	free(value);
	free(new_shlvl);
	return (new_env);
}

char	**init_local_env(char **env)
{
	char	**new_env;

	new_env = ft_dup_tab(env);
	if (!new_env)
		return (NULL);
	new_env = modify_shlvl(new_env);
	return (sort_env(new_env));
}
