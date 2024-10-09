/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:28:02 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 20:01:51 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"
#include "../../../include/exec.h"

int	ft_countpipes(char *str)
{
	int	index;
	int	pipe;

	index = 0;
	pipe = 0;
	while (str[index])
	{
		if (str[index] == '|' && !(is_char_in_quotes(str, index)))
			pipe++;
		index++;
	}
	return (pipe + 1);
}

void	cmd_handler(char *cmd_line, t_prompt *prompt, t_exec *exec)
{
	int			index;
	char		**cmd_split;
	int			nb_pipes;

	index = 0;
	nb_pipes = ft_countpipes(cmd_line);
	cmd_split = split_cmd_pipe(cmd_line, '|', 0);
	while (index < nb_pipes)
	{
		prompt->cmd = split_cmd(cmd_split[index], ' ');
		redirect_handler(cmd_split[index], prompt);
		if (prompt->cmd)
			prompt->path = get_path(prompt->cmd[0], exec->env);
		index++;
		if (index < nb_pipes)
			promptadd_back(&prompt, prompt_init());
		prompt = prompt->next;
	}
	ft_free_tab(cmd_split);
}
