/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/07/19 17:35:05 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void fake_init(char **env, t_prompt *prompt)
{
	//prompt->file->file = (char * )malloc(sizeof(char) * 4);
	prompt->file->file = "oui";
	prompt->file->mode = 0;
	prompt->cmd = (char **)malloc(sizeof(char *) * 3);
	prompt->cmd[0] = "ls";
	prompt->cmd[1] = "-la";
	prompt->cmd[2] = "\0";
	prompt->env = env;
	prompt->path = get_path(prompt->cmd[0], env);
	//free(env);
}

void	exec(t_prompt *prompt)
{
	//execve(prompt->cmd[0], prompt->cmd, prompt->env);
	ft_printf("%s, %d, %s %s, %s\n", prompt->file->file, prompt->file->mode, prompt->cmd[0], prompt->cmd[1], prompt->path);

}

int	main(int ac, char **av, char **env)
{
	t_prompt	*prompt;
	t_file		*file;

	file = malloc(sizeof(t_file));
	prompt = malloc(sizeof(t_prompt));
	prompt->file = file;
	fake_init(env, prompt);

	exec(prompt);
	free(prompt->cmd);
	free(prompt->path);
	free(prompt->file);
	free(prompt);



	
	if (av[0][0] == 'p')
		return (ac);
}
