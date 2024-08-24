/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:59:39 by emfourni          #+#    #+#             */
/*   Updated: 2024/08/24 17:29:40 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/minishell.h"

bool	ft_is_metachar(char c)
{
	if (c == '|' || c == '&' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
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
// 		if (!cmd_line[index] || ft_iswhitespace(cmd_line, ft_strlen(cmd_line)))
// 			return (ft_error_empty_cmd_line, free(cmd_line), prompt);
// 		if (!quotes_handler(cmd_line))
// 			return (free(cmd_line), prompt);
// 		if (!check_syntax(cmd_line))
// 			return (free(cmd_line), prompt);
// 		index++;
// 	}
// 	return (prompt);
// }

int	ft_onlywhitespace(char *str, int len)
{
	while (len > 0)
	{
		if (!ft_isspace(str[len]))
			return (0);
		len--;
	}
	return (1);
}
//NE PAS OUBLIER DE GERER LES LIGNES DE COMMANDES VIDES COMME ERREUR
// if (!cmd_line[index])
// 	return (ft_error_empty_cmd_line(), free(cmd_line), 0);

int	ft_lexer(char *cmd_line)
{
	size_t		index;

	index = 0;
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
