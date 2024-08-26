/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:14:48 by malia             #+#    #+#             */
/*   Updated: 2024/08/26 02:51:54 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**all_path;
	char	*pre_path;
	char	*path;

	i = 0;
	if (!cmd)
		return (NULL);
	all_path = ft_split(get_line_value("PATH", env), ':');
	if (!all_path)
		return (NULL);
	while (all_path[i])
	{
		pre_path = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(pre_path, cmd);
		free(pre_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free_tab(all_path), path);
		free(path);
		i++;
	}
	ft_free_tab(all_path);
	return (NULL);
}

char	*get_line_value(char *name, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(name, env[i], ft_strlen(name) - 1) == 0)
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}
