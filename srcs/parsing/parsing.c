/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/24 12:22:36 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/exec.h"

int	ft_checker(char *cmd_line)
{
	size_t		index;

	index = 0;
	if (!cmd_line[index])
		return (ft_error_empty_cmd_line(), 0);
	if (!quotes_handler(cmd_line))
		return (free(cmd_line), 0);
	if (!check_syntax(cmd_line))
		return (free(cmd_line), 0);
	return (1);
}

t_prompt	*ft_filler(char *cmd_line, t_prompt *prompt, t_exec *exec)
{
	// cmd_line = expand_var(exec, cmd_line);
	if (!cmd_line[0])
		return (free_prompt(&prompt), free(cmd_line), NULL);
	cmd_handler(cmd_line, prompt, exec);
	free(cmd_line);
	exec->n_cmd = len_prompt(prompt);
	return (prompt);
}
