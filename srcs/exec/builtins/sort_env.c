/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:42:20 by alia              #+#    #+#             */
/*   Updated: 2024/08/29 03:34:46 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static int	compare_str_until_char(char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while (s1[i] != c && s1[i] != c)
	{
		if (s1[i] != s2[i])
			return (s1[i] < s2[i]);
		i++;
	}
	return (s1[i] <= s2[i]);
}

static void	swap_tab(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static int	is_sorted(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (env[i + 1] && !compare_str_until_char(env[i], env[i + 1], '='))
			return (0);
		i++;
	}
	return (1);
}

char	**sort_env(char **env)
{
	int	i;

	while (!is_sorted(env))
	{
		i = 0;
		while (env[i])
		{
			if (env[i + 1] && !compare_str_until_char(env[i], env[i + 1], '='))
				swap_tab(&env[i], &env[i + 1]);
			i++;
		}
	}
	return (env);
}
