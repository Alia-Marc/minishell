/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:53:27 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/31 17:54:08 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_dollarsign_redirect(char *file, int index)
{
	int	temp;

	temp = index;
	while (file[index])
	{
		if (file[temp + 1] == '$')
			return (printf("ambiguous_redirect\n"), 0);
		else if (file[index] == '$' && index == ft_strlen(file) - 1)
			return (-1); // flag value to notify '$' is at the end and should be in file name
		else if (file[index] == '$')
			return (index - temp - 1); // to give out precisely the len of the string witouth '>' or '$'
		index++;
	}
	return (0);
}
