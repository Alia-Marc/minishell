/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 16:18:11 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == ' ' || c == '\t' || c == '\n'
		|| c == '(' || c == ')')
		return (true);
	return (false);
}

bool	ft_is_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (true);
	if (ft_strcmp(str, "cd") == 0)
		return (true);
	if (ft_strcmp(str, "pwd") == 0)
		return (true);
	if (ft_strcmp(str, "export") == 0)
		return (true);
	if (ft_strcmp(str, "unset") == 0)
		return (true);
	if (ft_strcmp(str, "env") == 0)
		return (true);
	if (ft_strcmp(str, "exit") == 0)
		return (true);
	else
		return (false);
}

// t_prompt	ft_lexer(char *cmd_line)
// {
// 	size_t		index;
// 	t_prompt	prompt;
// 	char		**pipe_split;

// 	while (cmd_line[index])
// 	{
// 		if (!cmd_line[index])
// 			return (ft_error_empty_cmd_line, free(cmd_line), prompt);
// 		if (!quotes_handler(cmd_line))
// 			return (ft_quote_error, free(cmd_line), prompt);
// 		if (!check_syntax(cmd_line))
// 			return (ft_syntax_error, free(cmd_line), prompt);
// 		index++;
// 	}
// 	return (prompt);
// }
