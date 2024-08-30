/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/08/30 21:41:39 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	exec_prompt(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;
	int			result_prev_pipe;
	
	tmp_prompt = prompt;
	result_prev_pipe = -2;
	while (tmp_prompt)
	{
		assign_fds(tmp_prompt, exec);
		if (exec->fd_in > 0 || result_prev_pipe == -2)
		{
			if (!isatty(result_prev_pipe) && result_prev_pipe > 2)
				close(result_prev_pipe);
			result_prev_pipe = handle_pipe(tmp_prompt, exec, exec->fd_in);
		}
		else
			result_prev_pipe = handle_pipe(tmp_prompt, exec, result_prev_pipe);
		if (exec->pid == 0)
			exit_free_all(prompt, exec);
		tmp_prompt = tmp_prompt->next;
	}
	if (!isatty(result_prev_pipe) && result_prev_pipe > 2)
		close(result_prev_pipe);
	wait_children(exec->pid);
}

void	exec_cmd(t_prompt *prompt, t_exec *exec)
{
	execve(prompt->cmd[0], prompt->cmd, exec->env);
	if (!prompt->path)
	{
		ft_fdprintf(2, "kimonOS: %s: command not found\n", prompt->cmd[0]);
		return ;
	}
	if (execve(prompt->path, prompt->cmd, exec->env) == -1)
	{
		ft_putstr_fd("ERROR CMD POURQUOI?\n", 2);
		return ;
	}
}

int	main(int ac, char **av, char **env)
{
	t_prompt	*prompt;
	t_exec		*exec;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));

	fake_init(env, prompt);
	//prompt->file = new_file("/dev/full", 1);
	//prompt->file = new_file("a", 0);
	//fileadd_back(&prompt->file, new_file("oui", 2));
	//fileadd_back(&prompt->file, new_file("i", 0));
	//fileadd_back(&prompt->file, new_file("k", 1));
	//fileadd_back(&prompt->file, new_file("oui", 1));
	//fileadd_back(&prompt->file, new_file("gay", 2));
	
	//promptadd_back(&prompt, new_prompt("export 7oui=da non=da", "o", "outfile", env, 0));
	//promptadd_back(&prompt, new_prompt("grep a", "j", "outfile", env, 1));
	//promptadd_back(&prompt, new_prompt("", "o", "outfile", env, 1));
	
	//promptadd_back(&prompt, new_prompt("ls", "o", "outfile", env, 0));
	//promptadd_back(&prompt, new_prompt("cd", "o", "outfile", env, 0));
	//promptadd_back(&prompt, new_prompt("", "o", "outfile", env, 0));

	exec = init_exec(env, prompt);
	open_close_redir(prompt); // un-comment to use redirections files
	//ft_printf("fd_in = %d, fd_out = %d\nlen prompt = %d\n\n\n", exec->fd_in, exec->fd_out, exec->n_cmd);

	exec_prompt(prompt, exec);
	if (!isatty(exec->fd_in) && exec->fd_in > 2)
		close(exec->fd_in);
	if (!isatty(exec->fd_out) && exec->fd_out > 2)
		close(exec->fd_out);
	free_prompt(&prompt);

	// int i = 0;
	// while (exec->env[i])
	// {
	// 	ft_printf("%s\n", exec->env[i]);
	// 	i++;
	// }

	char	*cmd;
	while (1)
	{
		cmd = readline("");
		if (ft_strncmp(cmd, "caca", 4) == 0)
			break;
		prompt = new_prompt(cmd, "o", "outfile", exec->env, 0);
		free(cmd);
		exec->fd_in = 0;
		exec->fd_out = 1;
		exec->n_cmd = len_prompt(prompt);
		open_close_redir(prompt);
		exec_prompt(prompt, exec);
		if (!isatty(exec->fd_in) && exec->fd_in > 2)
			close(exec->fd_in);
		if (!isatty(exec->fd_out) && exec->fd_out > 2)
			close(exec->fd_out);
		free_prompt(&prompt);
	}
	free(cmd);
	if (!isatty(exec->fd_in) && exec->fd_in > 2)
		close(exec->fd_in);
	if (!isatty(exec->fd_out) && exec->fd_out > 2)
		close(exec->fd_out);
	free_prompt(&prompt);
	ft_free_tab(exec->env);
	free(exec);

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


	(void) ac, (void) av;
	return (0);
}
