/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:53:30 by marc              #+#    #+#             */
/*   Updated: 2024/10/02 23:42:00 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNAL_H
# define MINISHELL_SIGNAL_H

# include "minishell.h"

void	set_signals_default(void);
int		init_sig(int signum, void (*function)(int));
void	handle_sigint_hd(int signum);
int		hd_sigint_skip(t_prompt *prompt, t_exec *exec);

void	handle_sigint_cmd(int signum);
void	handle_sigquit_cmd(int signum);

#endif
