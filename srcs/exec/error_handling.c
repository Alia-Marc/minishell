/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:39:25 by alia              #+#    #+#             */
/*   Updated: 2024/09/10 03:09:46 by marc             ###   ########.fr       */
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

// MDR c'est quoi ce fichier qui sert à rien