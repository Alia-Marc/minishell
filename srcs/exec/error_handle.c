/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:39:25 by alia              #+#    #+#             */
/*   Updated: 2024/07/30 19:23:49 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/exec.h"

void	error_handler(char *file, char *word, int code)
{
	ft_printf("%s%s", file, word);
	if (code == 0)
		perror("");
	//exit(code);
}
