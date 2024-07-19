/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:17:40 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 18:03:16 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	pipe_checker(char *cmd_line)
{
	size_t index;

	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '|' && ft_iswhitespace(cmd_line, index))
			return (0);
		else if (cmd_line[index] == '|' && ft_rev_iswhitespace(cmd_line, index))
			return (0);
		index++;
	}
	return (1);
}


