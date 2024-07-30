/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/27 15:29:11 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == ' ' || c == '\t' || c == '\n'
		|| c == '(' || c == ')' || c == '<' || c == '>')
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

// 	index = 0;
// 	pipe_split = NULL;
// 	while (cmd_line[index])
// 	{
// 		if (ft_isempty(cmd_line) || ft_iswhitespace(cmd_line, ft_strlen(cmd_line)))
// 			return (ft_error_empty_cmd_line, free(cmd_line), prompt);
// 		if (!quotes_handler(cmd_line))
// 			return (ft_quote_error, free(cmd_line), prompt);
// 		if (!check_syntax(cmd_line, prompt))
// 			return (ft_syntax_error, free(cmd_line), prompt);
// 		index++;
// 	}
// 	return (prompt);
// }
