/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:41:10 by marc              #+#    #+#             */
/*   Updated: 2024/09/18 22:23:10 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/exec.h"

static void	parse_and_exec(t_prompt *prompt, t_exec *exec, char *line)
{
	add_history(line);
	if (ft_checker(line))
	{
		prompt = ft_filler(line, prompt_init(), exec);
		if (prompt)
		{
			if (open_close_redir(prompt))
				exec_prompt(prompt, exec);
			else
				exec->exit = 1;
			free_prompt(&prompt);
		}
	}
	else
		exec->exit = 2;
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
		line = readline("kimonOS > ");
		if (ft_strcmp(line, "caca") == 0)
		{
			free(line);
			break ;
		}
		if (!line[0])
			continue ;
		parse_and_exec(prompt, exec, line);
		reset_exec(exec);
	}
	exit_free_all(prompt, exec, exec->exit);
}
