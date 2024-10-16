/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:22:35 by emilefourni       #+#    #+#             */
/*   Updated: 2024/10/10 14:48:48 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"
#include "../../../include/minishell.h"

void	redirect_filler(char *cmd_line, int index, t_prompt *prompt, int mode)
{
	char	*file_name;

	file_name = NULL;
	while (index < ft_strlen(cmd_line))
	{
		if (!ft_isspace(cmd_line[index]) && !ft_is_metachar(cmd_line[index]))
		{
			file_name = ft_strdupnospace(cmd_line, index);
			fileadd_back(&prompt->file, create_new_file(file_name, mode));
			break ;
		}
		else if (ft_isspace(cmd_line[index]))
			index++;
		else
			index++;
	}
}

void	redirect_handler(char *cmd_line, t_prompt *prompt)
{
	int	i;

	i = 0;
	if (!cmd_line)
		return ;
	while (cmd_line[i])
	{
		skip_in_quotes(cmd_line, &i);
		if (cmd_line[i] == '>' && cmd_line[i + 1] == '>')
			redirect_filler(cmd_line, i, prompt, 2);
		else if (cmd_line[i] == '<' && cmd_line[i + 1] == '<')
			redirect_filler(cmd_line, i, prompt, 3);
		else if (i > 0 && cmd_line[i] == '>' && cmd_line[i - 1] != '>')
			redirect_filler(cmd_line, i, prompt, 1);
		else if (i > 0 && cmd_line[i] == '<' && cmd_line[i - 1] != '<')
			redirect_filler(cmd_line, i, prompt, 0);
		else if (i == 0 && cmd_line[i] == '>')
			redirect_filler(cmd_line, i, prompt, 1);
		else if (i == 0 && cmd_line[i] == '<')
			redirect_filler(cmd_line, i, prompt, 0);
		if (cmd_line[i])
			i++;
	}
}
