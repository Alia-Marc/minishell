/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/07/24 23:10:53 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	exec(t_prompt *prompt)
{
	//execve(prompt->cmd[0], prompt->cmd, prompt->env);
	ft_printf("%s, %d, %s %s, %s\n", prompt->file->file, prompt->file->mode, prompt->cmd[0], prompt->cmd[1], prompt->path);

}

void	printtest(t_prompt *prompt)
{
	t_file		*tmp;
	t_prompt	*t;

	t = prompt;

	while (t)
	{
		tmp = t->file;
		ft_printf("%s, %d\n", tmp->file, tmp->mode);
		tmp = tmp->next;
		ft_printf("%s, %d\n", tmp->file, tmp->mode);
		ft_printf("%s %s, %s\n", t->cmd[0], t->cmd[1], t->path);
		t = t->next;
	}

}

int	main(int ac, char **av, char **env)
{
	t_prompt	*prompt;

//	file = (t_file *)malloc(sizeof(t_file));
	prompt = (t_prompt *)malloc(sizeof(t_prompt));
//	prompt->file = file;

	prompt->file = new_file("oui", 0);
	fake_init(env, prompt);
	fileadd_back(&prompt->file, new_file("non", 1));
	fileadd_back(&prompt->file, new_file("bah", 2));
	fileadd_back(&prompt->file, new_file("gay", 0));
	
	//prompt->next = new_prompt("cat", "-e", "p", "d", env);
	promptadd_back(&prompt, new_prompt("cat", "-e", "p", "d", env));
	printtest(prompt);

	//exec(prompt);
	free_prompt(&prompt);
	//free(prompt->cmd);
	//free(prompt->path);
	//free_file(&prompt->file);
	//free(prompt->file);
	//free(prompt);



	
	if (av[0][0] == 'p')
		return (ac);
}
