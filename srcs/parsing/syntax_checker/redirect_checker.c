/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:51:53 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/18 20:18:43 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_is_redirect(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int	nb_redirect(char *str)
{
	int	index;
	int	pos_redirect;

	index = 0;
	pos_redirect = 0;
	while (str[index])
	{
		if (ft_is_redirect(str[index]))
			pos_redirect = index;
		if ((str[index] == '>' && str[index + 1] == '<')
			|| (str[index] == '<' && str[index + 1] == '>'))
			return (too_many_redirect(), 0);
		if (ft_is_redirect(str[pos_redirect + 2]))
			return (too_many_redirect(), 0);
		index++;
	}
	return (1);
}

int	check_parenthesis(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
	{
		if (ft_is_redirect(str[index]))
		{
			while (str[index])
			{
				if (str[index] == '(' || str[index] == ')')
					return (ft_metachar_near_token(), 0);
				index++;
			}
		}
		if (str[index])
			index++;
	}
	return (1);
}

int	check_empty_name(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_is_redirect(str[index]))
		{
			index++;
			if (ft_is_redirect(str[index]))
				index++;
			while (ft_isspace(str[index]) && str[index])
				index++;
			if (ft_is_redirect(str[index]) || str[index] == '|'
				|| !str[index])
				return (ft_redirect_name_empty(), 0);
		}
		index++;
	}
	return (1);
}

int	redirect_checker(char *cmd_line)
{
	// int	index;

	// index = 0;
	// while (cmd_line[index])
	// {
		if (!nb_redirect(cmd_line))
			return (0);
		if (!check_parenthesis(cmd_line))
			return (0);
		if (!check_empty_name(cmd_line))
			return (0);
		if (!ft_dollarsign_redirect(cmd_line))
			return (0);
		// index++;
	// }
	return (1);
}
