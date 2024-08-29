/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:02:50 by marc              #+#    #+#             */
/*   Updated: 2024/08/29 03:30:37 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

char	**make_env(char **env)
{
	char	**new_env;

	new_env = ft_dup_tab(env);
	if (!new_env)
		return (NULL);
	new_env = sort_env(new_env);
	return (new_env);
}

// Doit gérer le shlevel, s'il n'existe pas et de gérer si le PWD n'éxiste pas aussi