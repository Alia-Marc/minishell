/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:15 by malia             #+#    #+#             */
/*   Updated: 2024/10/03 06:52:57 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

static void	exit_command(t_prompt *prompt, t_exec *exec, int fd, t_prompt *tmp)
{
	if (exec->pid == 0 || (!ft_strncmp(tmp->cmd[0], "exit", 4) && !tmp->next
		&& (ft_strlen2(tmp->cmd) <= 2 || !exit_check_first_arg(tmp->cmd[1]))
		&& exec->n_cmd == 1))
	{
		if (!isatty(fd) && fd > 2)
			close(fd);
		exit_free_all(prompt, exec, exec->exit);
	}
}

void	exec_prompt(t_prompt *prompt, t_exec *exec)
{
	t_prompt	*tmp_prompt;
	int			prev_pipe;
	
	tmp_prompt = prompt;
	prev_pipe = -2;
	while (tmp_prompt)
	{
		if (tmp_prompt->cmd && tmp_prompt->error == 0)
		{
			assign_fds(tmp_prompt, exec);
			if (is_builtin(tmp_prompt) && exec->n_cmd == 1) //|| !tmp_prompt->next
				exec->exit = exec_solo_builtin(tmp_prompt, exec);
			else
			{
				if (exec->fd_in <= 2 && prev_pipe > 2)
					exec->fd_in = prev_pipe;
				else if (!isatty(prev_pipe) && prev_pipe > 2)
					close(prev_pipe);
				prev_pipe = handle_pipe(tmp_prompt, exec, exec->fd_in);
			}
			// else
			// {
			// 	if (exec->fd_in > 0 || prev_pipe == -2)
			// 	{
			// 		if (!isatty(prev_pipe) && prev_pipe > 2)
			// 			close(prev_pipe);
			// 		prev_pipe = handle_pipe(tmp_prompt, exec, exec->fd_in);
			// 	}
			// 	else
			// 		prev_pipe = handle_pipe(tmp_prompt, exec, prev_pipe);
			// }
			exit_command(prompt, exec, prev_pipe, tmp_prompt);
		}
		else if (tmp_prompt->error)
			exec->exit = 1;
		tmp_prompt = tmp_prompt->next;
	}
	close_unused_next_hd(prompt, 0);
	if (!isatty(prev_pipe) && prev_pipe > 2)
		close(prev_pipe);
	if (is_builtin(prompt) && exec->n_cmd == 1)
		return ;
	exec->exit = wait_children(exec, exec->pid);
}

void	exec_cmd(t_prompt *prompt, t_exec *exec)
{
	close_unused_next_hd(prompt, 1);
	execve(prompt->cmd[0], prompt->cmd, exec->env);
	if (check_char(prompt->cmd[0], '/'))
	{
		ft_fdprintf(2, NO_SUCH_FILE_OR_DIR, prompt->cmd[0]);
		exec->exit = 127;
	}
	else if (!prompt->path)
	{
		ft_fdprintf(2, COMMAND_NOT_FOUND, prompt->cmd[0]);
		exec->exit = 127;
	}
	else if (execve(prompt->path, prompt->cmd, exec->env) == -1)
	{
		ft_fdprintf(2, "ERROR COMMAND POURQUOI\n");
		exec->exit = 1;
	}
}

// int	main(int ac, char **av, char **env)
// {
// 	t_prompt	*prompt;
// 	t_exec		*exec;

// 	prompt = (t_prompt *)malloc(sizeof(t_prompt));

// 	fake_init(env, prompt);
// 	//prompt->file = new_file("/dev/full", 1);
// 	//prompt->file = new_file("bah", 1);
// 	// fileadd_back(&prompt->file, new_file("oui", 2));
// 	// fileadd_back(&prompt->file, new_file("da", 2));
// 	//fileadd_back(&prompt->file, new_file("eheh", 0));
// 	//fileadd_back(&prompt->file, new_file("k", 1));
// 	//fileadd_back(&prompt->file, new_file("oui", 1));
// 	//fileadd_back(&prompt->file, new_file("gay", 2));
	
// 	//promptadd_back(&prompt, new_prompt("export 7oui=da non=da", "o", "outfile", env, 0));
// 	//promptadd_back(&prompt, new_prompt("grep o", "o", "outfile", env, 1));
// 	//promptadd_back(&prompt, new_prompt("exit 32d", "j", "outfile", env, 1));
// 	//promptadd_back(&prompt, new_prompt("ls", "j", "outfile", env, 1));
	
// 	//promptadd_back(&prompt, new_prompt("env", "a", "outfile", env, 0));
// 	//promptadd_back(&prompt, new_prompt("cd", "o", "outfile", env, 0));
// 	//promptadd_back(&prompt, new_prompt("", "o", "outfile", env, 0));

// 	exec = init_exec(env, prompt);
// 	if (open_close_redir(prompt)) // un-comment to use redirections files
// 		exec_prompt(prompt, exec);
// 	else
// 		exec->exit = 1;
// 	ft_fdprintf(2, "%d\n", exec->exit);
// 	if (!isatty(exec->fd_in) && exec->fd_in > 2)
// 		close(exec->fd_in);
// 	if (!isatty(exec->fd_out) && exec->fd_out > 2)
// 		close(exec->fd_out);
// 	free_prompt(&prompt);

// 	// int i = 0;
// 	// while (exec->env[i])
// 	// {
// 	// 	ft_printf("%s\n", exec->env[i]);
// 	// 	i++;
// 	// }

// 	char	*cmd;
// 	while (1)
// 	{
// 		cmd = readline("");
// 		if (ft_strncmp(cmd, "caca", 4) == 0)
// 			break;
// 		add_history(cmd);
// 		cmd = expand_var(exec, cmd);
// 		prompt = new_prompt(cmd, "o", "outfile", exec->env, 0);
// 		free(cmd);
// 		reset_exec(prompt, exec);
// 		if (open_close_redir(prompt))
// 			exec_prompt(prompt, exec);
// 		else
// 			exec->exit = 1;
// 		ft_fdprintf(2, "%d\n", exec->exit);
// 		free_prompt(&prompt);
// 	}
// 	free(cmd);
// 	if (!isatty(exec->fd_in) && exec->fd_in > 2)
// 		close(exec->fd_in);
// 	if (!isatty(exec->fd_out) && exec->fd_out > 2)
// 		close(exec->fd_out);
// 	free_prompt(&prompt);
// 	ft_free_tab(exec->env);
// 	free(exec);
// 	rl_clear_history();

// /*
// 	char	**tcmd;
// 	char	*path;
// 	int		i = 0;
	
// 	tcmd = ft_split(av[1], ' ');
// 	path = get_path(tcmd[0], env);
// 	ft_printf("%d\n", ft_strlen2(tcmd));
// 	while (tcmd[i])
// 	{
// 		ft_printf("%s\n", tcmd[i]);
// 		i++;
// 	}
// 	execve(path, tcmd, env);
// 	*/


// 	(void) ac, (void) av;
// 	return (0);
// }
