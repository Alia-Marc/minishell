/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:41:10 by marc              #+#    #+#             */
/*   Updated: 2024/09/24 17:46:31 by emfourni         ###   ########.fr       */
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

// void	print_split(char **split)
// {
// 	int index;

// 	index = 0;
// 	while (split[index])
// 		printf("%s\n", split[index++]);
// }

// int main(int argc, char *argv[])
// {
// 	char **split;

// 	split = NULL;
// 	split = split_cmd(argv[1], ' ');
// 	print_split(split);
// 	return argc;
// }


// int main(int argc, char **argv, char **env)
// {
// 	t_exec		*exec;
// 	t_prompt	*prompt;

// 	(void) argc;
// 	exec = init_exec(env);
// 	prompt = NULL;
// 	if (!exec)
// 		return (1);
// 	parse_and_exec(prompt, exec, argv[1]);
// 	reset_exec(exec);
// 	exit_free_all(prompt, exec, exec->exit);
// 	return argc;
// }


