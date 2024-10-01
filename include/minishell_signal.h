/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:53:30 by marc              #+#    #+#             */
/*   Updated: 2024/10/01 03:42:31 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNAL_H
# define MINISHELL_SIGNAL_H

# include "minishell.h"

void	set_signals_default(void);
int		init_sig(int signum, void (*function)(int));
void	handle_sigint_hd(int signum);
int		hd_sigint_skip(t_prompt *prompt, t_exec *exec);

#endif
