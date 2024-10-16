/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:08:53 by malia             #+#    #+#             */
/*   Updated: 2024/10/10 15:09:07 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	copy_expand_end_tab(char *line, char *result, int *i, int *j)
{
	result[*j] = line[*i];
	(*i)++;
	(*j)++;
}
