/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:30:06 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/04 17:17:29 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	check_syntax(char *cmd_line)
{
	if (!pipe_checker(cmd_line) || !redirect_checker(cmd_line))
		return (0);
	return (1);
}
