/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/07/15 16:42:56 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void fake_init(char **env, t_prompt *prompt)
{
	prompt->file = "oui";
	prompt->cmd[0] = "cat";
	prompt->env = env;
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**all_path;
	char	*pre_path;
	char	*path;

	i = 0;
	all_path = ft_split(get_line_value("PATH", env), ':');
	if (!all_path)
		exit_handler(-2);
	while (all_path[i])
	{
		pre_path = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(pre_path, cmd);
		free(pre_path);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_free_tab(all_path);
	return (cmd);
}

void	exec(t_prompt *prompt)
{

}

int	main(char **env)
{
	t_prompt *prompt;

	fake_init(env, &prompt);
	exec(&prompt);
}