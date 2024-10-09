/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_or_no_skip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:53:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 19:53:34 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

void	skip_or_no_skip(char *s, int *j, int *t, char c)
{
	if (ft_is_redirect(s[*j]))
	{
		*j = redirect_skip(s, *j, c);
		*t = redirect_skip(s, *t, c);
	}
	else
	{
		(*t)++;
		(*j)++;
	}
}
