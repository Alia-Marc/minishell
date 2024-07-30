/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/07/28 22:59:19 by alia             ###   ########.fr       */
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

	prompt->file = new_file("i", 1);
	fake_init(env, prompt);
	fileadd_back(&prompt->file, new_file("a", 1));
	fileadd_back(&prompt->file, new_file("k", 1));
	fileadd_back(&prompt->file, new_file("emile", 3));
	
	//prompt->next = new_prompt("cat", "-e", "p", "d", env);
	promptadd_back(&prompt, new_prompt("cat", "-e", "o", "b", env));
	printtest(prompt);
	open_redir_files(prompt);

	//exec(prompt);
	free_prompt(&prompt);
	//free(prompt->cmd);
	//free(prompt->path);
	//free_file(&prompt->file);
	//free(prompt->file);
	//free(prompt);

	char	**tcmd;
	char	*path;
	int		i = 0;
	
	tcmd = ft_split(av[1], ' ');
	path = get_path(tcmd[0], env);
	ft_printf("%d\n", ft_strlen2(tcmd));
	while (tcmd[i])
	{
		ft_printf("%s\n", tcmd[i]);
		i++;
	}
	execve(path, tcmd, env);





		return (ac);
}
