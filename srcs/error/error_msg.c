/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:09:38 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/21 12:42:50 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_error_empty_cmd_line(void)
{
	printf("Tia un pb de readline ou c vide ton truc le S\n");
}

void	ft_quote_error(void)
{
	printf("Mais tie un tigre toi, fais belleck aux quotes\n");
}

void	ft_syntax_error(void)
{
	printf("Achete-toi un Beschrelle le S ta syntaxe est claquee\n");
}
