/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:30:06 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/26 12:24:09 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_syntax(char *cmd_line)
{
 	if (!pipe_checker(cmd_line) || !redirect_checker(cmd_line))
 		return (0);
 	return (1);
}
