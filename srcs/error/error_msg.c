/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:09:38 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/30 17:47:09 by emfourni         ###   ########.fr       */
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
	printf("Achete-toi un Beschrelle le S tia la syntaxe claquee\n");
}

void	ft_metachar_near_token(void)
{
	printf("frerot tia un plem avec le nom d'un file le S\n");
}
