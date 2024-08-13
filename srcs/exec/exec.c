/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/08/13 06:49:32 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	exec_prompt(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;
	
	tmp_prompt = prompt;
	//dup2(exec->fd_out, STDOUT_FILENO);
	exec_cmd(tmp_prompt, exec);
	// while (tmp_prompt)
	// {
	// 	handle_pipe(tmp_prompt, exec);

	// 	tmp_prompt = tmp_prompt->next;
	// }
}

void	exec_cmd(t_prompt *prompt, t_exec *exec)
{
	//char *path = get_path(prompt->cmd[0], prompt->env);

	if (execve(prompt->path, prompt->cmd, exec->env) == -1)
	{
		ft_printf("ERROR CMD");
	}
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
	t_exec		*exec;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	exec = init_exec(env);

	prompt->file = new_file("i", 0);
	fake_init(env, prompt);
	fileadd_back(&prompt->file, new_file("a", 0));
	fileadd_back(&prompt->file, new_file("k", 1));
	fileadd_back(&prompt->file, new_file("emile", 2));
	//fileadd_back(&prompt->file, new_file("gay", 0));
	
	promptadd_back(&prompt, new_prompt("grep", "u", "o", "b", env));
	printtest(prompt);
	open_redir_files(prompt, exec);

	ft_printf("fd_in = %d, fd_out = %d\n", exec->fd_in, exec->fd_out);

	exec_prompt(prompt, exec);
	free_prompt(&prompt);
	free(exec);
	//free(prompt->cmd);
	//free(prompt->path);
	//free_file(&prompt->file);
	//free(prompt->file);
	//free(prompt);
/*
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
	*/



	if (av[0][0] == 'p')
		return (ac);
}
