/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:31:06 by alia              #+#    #+#             */
/*   Updated: 2024/08/29 18:31:23 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	check_var_exist(char **env, char *arg)
{
	int	len_var;
	int	i;

	len_var = ft_strlen_until_char(arg, '=');
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], arg, len_var) == 0)
			return (1);
		i++;
	}
	return (0);
}
