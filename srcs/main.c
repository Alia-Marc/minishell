/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:41:10 by marc              #+#    #+#             */
/*   Updated: 2024/10/09 19:23:51 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/exec.h"

int	g_signal = 0;

static void	parse_and_exec(t_prompt *prompt, t_exec *exec, char *line)
{
	add_history(line);
	if (ft_checker(line))
	{
		prompt = ft_filler(line, prompt_init(), exec);
		if (prompt)
		{
			if (open_close_redir(prompt, exec))
				exec_prompt(prompt, exec);
			free_prompt(&prompt);
		}
	}
	else
		exec->exit = 2;
}

static int	checks_before_parse(t_prompt *prompt, t_exec *exec, char *line)
{
	if (g_signal == SIGINT)
		exec->exit = 130;
	g_signal = 0;
	if (!line && ft_fdprintf(2, "exit\n"))
		exit_free_all(prompt, exec, exec->exit);
	if (!line[0])
		return (0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_exec		*exec;
	t_prompt	*prompt;
	char		*line;

	(void) ac, (void) av;
	exec = init_exec(env);
	prompt = NULL;
	if (!exec)
		return (1);
	while (1)
	{
		set_signals_default();
		line = readline("kimonOS > ");
		if (checks_before_parse(prompt, exec, line))
			parse_and_exec(prompt, exec, line);
		reset_exec(exec);
	}
	exit_free_all(prompt, exec, exec->exit);
}
