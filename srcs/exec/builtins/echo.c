/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:37:04 by marc              #+#    #+#             */
/*   Updated: 2024/08/26 13:56:50 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

static char	**skip_n(t_prompt *prompt, int *print_nl)
{
	char	**cmd;
	int		i;
	int		j;

	cmd = prompt->cmd;
	i = 1;
	*print_nl = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j])
			{
				if (cmd[i][j] != 'n')
					return (&cmd[i]);
				j++;
			}
			*print_nl = 0;
		}
		else
			return (&cmd[i]);
		i++;
	}
	return (&cmd[i]);
}

int	echo_builtin(t_prompt *prompt)
{
	char	**cmd;
	int		print_nl;
	int		i;

	cmd = skip_n(prompt, &print_nl);
	i = 0;
	while (cmd[i])
	{
		if (i > 0)
			write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, cmd[i], ft_strlen(cmd[i]));
		i++;
	}
	if (print_nl)
		write(STDOUT_FILENO, "\n", 1);
	return (errno);
}


// int	use_n(t_prompt *prompt)
// {
// 	char	**cmd;
// 	int		i;
// 	int		j;

// 	cmd = prompt->cmd;
// 	i = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
// 			return (0);
// 		j = 2;
// 		while (cmd[i][j])
// 		{
// 			if (cmd[i][j] != 'n')
// 				return (0);
// 			j++;
// 		}
// 	}
// 	return (1);
// }

// int	echo_builtin(t_prompt *prompt)
// {
// 	int	use_n_option;
// 	int	len_cmd;

// 	use_n_option = use_n(prompt);
// 	len_cmd = ft_strlen2(prompt->cmd);
// 	ft_printf("%d", len_cmd);
// 	if (use_n_option)
// 		write(STDOUT_FILENO, prompt->cmd[len_cmd - 1], ft_strlen(prompt->cmd[len_cmd - 1]));
// 	else
// 	{
// 		write(STDOUT_FILENO, prompt->cmd[len_cmd - 1]);
// 		write(STDOUT_FILENO, "\n", 1);
// 	}
// 	return (errno);
// }
