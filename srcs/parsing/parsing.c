/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/09 14:44:22 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/minishell.h"

int	ft_checker(char *cmd_line)
{
	size_t		index;

	index = 0;
	if (!cmd_line[index])
		return (ft_error_empty_cmd_line(), 0);
	while (cmd_line[index])
	{
		if (!quotes_handler(cmd_line))
			return (free(cmd_line), 0);
		if (!check_syntax(cmd_line))
			return (free(cmd_line), 0);
		index++;
	}
	return (1);
}

void	ft_filler(char *cmd_line)
{
	t_prompt	*prompt;
	int			index;

	index = 0;
	prompt = NULL;
	prompt = prompt_init(prompt);
	cmd_handler(cmd_line, prompt);
}
