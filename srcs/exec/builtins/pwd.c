/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:33:31 by marc              #+#    #+#             */
/*   Updated: 2024/08/23 15:24:36 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	pwd_builtin(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (!pwd)
		strerror(errno);
	else
	{
		write(STDOUT_FILENO, pwd, ft_strlen(pwd));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(pwd);
	return (errno);
}
