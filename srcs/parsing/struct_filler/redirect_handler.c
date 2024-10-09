/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:22:35 by emilefourni       #+#    #+#             */
/*   Updated: 2024/10/09 18:44:46 by emfourni         ###   ########.fr       */
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

void	skip_in_quotes(char *str, int *i)
{
	if (str[*i] == 34)
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 34)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
	if (str[*i] == 39)
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] == 39)
			{
				(*i)++;
				break ;
			}
			(*i)++;
		}
	}
}

void	redirect_handler(char *cmd_line, t_prompt *prompt)
{
	int	index;

	index = 0;
	if (!cmd_line)
		return ;
	while (cmd_line[index])
	{
		skip_in_quotes(cmd_line, &index);
		if (cmd_line[index] == '>' && cmd_line[index + 1] == '>')
			redirect_filler(cmd_line, index, prompt, 2);
		else if (cmd_line[index] == '<' && cmd_line[index + 1] == '<')
			redirect_filler(cmd_line, index, prompt, 3);
		else if (index > 0 && cmd_line[index] == '>' && cmd_line[index - 1] != '>')
			redirect_filler(cmd_line, index, prompt, 1);
		else if (index > 0 && cmd_line[index] == '<' && cmd_line[index - 1] != '<')
			redirect_filler(cmd_line, index, prompt, 0);
		if (cmd_line[index])
			index++;
	}
}
