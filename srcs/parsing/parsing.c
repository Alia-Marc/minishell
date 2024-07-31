/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/31 17:38:02 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
	return (false);
}

int	ft_dollarsign_redirect(char *file, int index)
{
	int	temp;

	temp = index;
	while (file[index])
	{
		if (file[temp + 1] == '$')
			return (printf("ambiguous_redirect"), 0);
		else if (file[index] == '$')
			return (index);
		else if (file[index] == ft_strlen(file) - 1)
			return (-1); // flag value to notify '$' is at the end and should be in file name
		index++;
	}
	return (0);
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
// 		if (!cmd_line[index] || ft_iswhitespace(cmd_line, ft_strlen(cmd_line)))
// 			return (ft_error_empty_cmd_line, free(cmd_line), prompt);
// 		if (!quotes_handler(cmd_line))
// 			return (ft_quote_error, free(cmd_line), prompt);
// 		if (!check_syntax(cmd_line, prompt))
// 			return (ft_syntax_error, free(cmd_line), prompt);
// 		index++;
// 	}
// 	return (prompt);
// }
