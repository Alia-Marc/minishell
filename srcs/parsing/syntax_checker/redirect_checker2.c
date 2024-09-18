/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checker2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:17:57 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/06 11:26:06 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_dollarsign_redirect(char *cmd_line)
{
	int index;

	index = 0;
	while (cmd_line[index])
	{
		if (ft_is_redirect(cmd_line[index]))
		{
			if (cmd_line[index + 1] == '$' && (cmd_line[index + 2] != '$'
				|| ft_isspace(cmd_line[index + 2])))
				return (ft_redirect_name_empty(), 0);
		}
		index++;
	}
	return (1);
}
