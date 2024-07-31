/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:22:35 by emilefourni       #+#    #+#             */
/*   Updated: 2024/07/31 16:52:03 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_redirect_check(char *cmd_line, int index)
{

}

void	ft_redirect_filler(char *cmd_line, int index, t_prompt *prompt, int mode)
{
	char	*file_name;

	file_name = NULL;
	while (index < ft_strlen(cmd_line))
	{
		if (!ft_isspace(cmd_line[index]) && !ft_is_metachar(cmd_line[index]))
		{
			file_name = ft_strdupnospace(cmd_line, index);
			fileadd_back(&prompt->file, create_new_file(file_name, mode));
		}
		else if (ft_isspace(cmd_line[index]))
			index++;
		else
			index++;
	}
}

int	redirect_handler(char *cmd_line, t_prompt *prompt)
{
	int	index;

	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '>' && cmd_line[index + 1] == '>' && ft_redirect_check(cmd_line, index))
			ft_redirect_filler(cmd_line, index, prompt, 2);
		else if (cmd_line[index] == '>' && ft_redirect_check(cmd_line, index))
			ft_redirect_filler(cmd_line, index, prompt, 1);
		else if (cmd_line[index] == '<' && ft_redirect_check(cmd_line, index))
			ft_redirect_filler(cmd_line, index, prompt, 0);
		index++;
	}
	return (1);
}