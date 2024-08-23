/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:39:25 by alia              #+#    #+#             */
/*   Updated: 2024/08/23 14:29:23 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	error_handler(char *file, char *word, int code)
{
	ft_printf("%s%s", file, word);
	if (code == 0)
		perror("");
	//exit(code);
}
