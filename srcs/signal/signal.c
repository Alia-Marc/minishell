/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:03 by malia             #+#    #+#             */
/*   Updated: 2024/10/03 01:05:04 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

int	hd_sigint_skip(t_prompt *prompt, t_exec *exec)
{
	exec->exit = 130;
	g_signal = 0;
	close_unused_next_hd(prompt, 0);
	return (1);
}

void	handle_sigint(int signum)
{
	g_signal = signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sigint_hd(int signum)
{
	g_signal = signum;
	close(STDIN_FILENO);
	write(1, "\n", 1);
}

int	init_sig(int signum, void (*function)(int))
{
	struct sigaction	sa;

	sa.sa_handler = function;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	return (sigaction(signum, &sa, NULL));
}

void	set_signals_default(void)
{
	init_sig(SIGINT, &handle_sigint);
	init_sig(SIGQUIT, SIG_IGN);
}
