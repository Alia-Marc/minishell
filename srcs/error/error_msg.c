/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:09:38 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/19 16:07:21 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_error_empty_cmd_line(void)
{
	write(2, "Tia un pb de readline ou c vide ton truc le S\n", 46);
}

void	ft_quote_error(void)
{
	write(2, "Mais tie un tigre toi, fais belleck aux quotes\n", 47);
}

void	ft_syntax_error(void)
{
	write(2, "Achete-toi un Beschrelle le S tia la syntaxe claquee\n", 53);
}

void	ft_metachar_near_token(void)
{
	write(2, "frerot tia une erreur a cote d'un token surprenant\n", 52);
}

void	ft_redirect_name_empty(void)
{
	write(2, "m'emboucane pas le zin, tie ambigu dans les redirect\n", 54);
}
