/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:33:31 by marc              #+#    #+#             */
/*   Updated: 2024/08/31 02:57:46 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	pwd_builtin(t_exec *exec)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (!pwd)
		strerror(errno);
	else
	{
		write(exec->fd_out, pwd, ft_strlen(pwd));
		write(exec->fd_out, "\n", 1);
	}
	free(pwd);
	return (0);
}
