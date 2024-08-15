/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/08/15 05:22:28 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	exec_prompt(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;
	int			i;
	int			result_prev_pipe;
	
	tmp_prompt = prompt;
	i = 1;
	result_prev_pipe = -2;
	while (i < exec->n_cmd)
	{
		assign_fds(tmp_prompt, exec);
		if (exec->fd_in > 0 || result_prev_pipe == -2)
			result_prev_pipe = handle_pipe(tmp_prompt, exec, exec->fd_in);
		else
			result_prev_pipe = handle_pipe(tmp_prompt, exec, result_prev_pipe);
		tmp_prompt = tmp_prompt->next;
		i++;
	}
	assign_fds(tmp_prompt, exec);
	if (exec->fd_in > 0)
		exec->pid = last_pipe(tmp_prompt, exec, exec->fd_in);
	else
		exec->pid = last_pipe(tmp_prompt, exec, result_prev_pipe);
	wait_children(exec->pid);
}

void	exec_cmd(t_prompt *prompt, t_exec *exec)
{
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

	fake_init(env, prompt);
	prompt->file = new_file("i", 0);
	fileadd_back(&prompt->file, new_file("a", 0));
	//fileadd_back(&prompt->file, new_file("k", 1));
	fileadd_back(&prompt->file, new_file("emile", 1));
	//fileadd_back(&prompt->file, new_file("gay", 0));
	
	promptadd_back(&prompt, new_prompt("grep e", "o", "outfile", env, 1));
	//promptadd_back(&prompt, new_prompt("cat", "o", "outfile", env, 1));
	//promptadd_back(&prompt, new_prompt("ls", "o", "outfile", env, 0));
	//printtest(prompt);
	exec = init_exec(env, prompt);
	
	open_redir_files(prompt); // un-comment to use redirections files

	//ft_printf("fd_in = %d, fd_out = %d\nlen prompt = %d\n\n\n", exec->fd_in, exec->fd_out, exec->n_cmd);

	exec_prompt(prompt, exec);
	
	
	if (exec->fd_out > 2)
		close(exec->fd_out);
	if (exec->fd_in > 2)
		close(exec->fd_in);
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
