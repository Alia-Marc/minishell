/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:15:01 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/10 12:30:22 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_bad_pipe_msg(void)
{
	write(2, "tia une erreur ton pipe il est en carton\n", 41);
}

void	too_many_redirect(void)
{
	write(2, "tia trop de chevrons dans le redirect, tie baise le S\n", 56);
}
