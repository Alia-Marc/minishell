/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:40:48 by alia              #+#    #+#             */
/*   Updated: 2024/10/03 00:29:11 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	handle_sigint_cmd(int signum)
{
	g_signal = signum;
	ft_putchar_fd('\n', 1);
}

// void	handle_sigquit_cmd(int signum)
// {
// 	g_signal = signum;
// 	// ft_putstr_fd("Quit core dumped\n", 2);
// }
