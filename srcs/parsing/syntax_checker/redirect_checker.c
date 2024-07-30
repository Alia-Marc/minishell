/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:22:35 by emilefourni       #+#    #+#             */
/*   Updated: 2024/07/27 15:27:15 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int ft_outfile_handler(char *cmd_line, int index, t_prompt *prompt)
{
    int i;

    i = 0;
    while (index < ft_strlen(cmd_line))
    {
        if (ft_isspace(cmd_line[index]))
            index++;
        else if (!ft_isspace(cmd_line[index]) && !ft_is_metachar(cmd_line[index]))
        {
            while (!ft_isspace(cmd_line[index]))
            {
                prompt->file->file[i++] = cmd_line[index++];
                prompt->file->mode = 1;
            }
            return (1);
        }
    }
    return (0);
}

int ft_infile_handler(char *cmd_line, int index, t_prompt *prompt)
{
    int i;

    i = 0;
    while (index < ft_strlen(cmd_line))
    {
        if (ft_isspace(cmd_line[index]))
            index++;
        else if (!ft_isspace(cmd_line[index]) && !ft_is_metachar(cmd_line[index]))
        {
            while (!ft_isspace(cmd_line[index]))
            {
                prompt->file->file[i++] = cmd_line[index++];
                prompt->file->mode = 0;
            }
            return (1);
        }
    }
    return (0);
}

int redirect_checker(char *cmd_line, t_prompt prompt)
{
    int index;

    index = 0;
    while (cmd_line[index])
    {
        if (cmd_line[index] == '>' && !ft_outfile_handler(cmd_line, index, &prompt))
            return (ft_metachar_near_token(), 0);
        else if (cmd_line[index] == '<')
            ft_infile_handler(cmd_line, index, &prompt);
        else if (cmd_line[index] == '>' && cmd_line[index + 1] == '>')
            ft_outfile_append(cmd_line, index, &prompt);
        else if (cmd_line[index] == '<' && cmd_line[index + 1] == '<')
            ft_delimiter(cmd_line, index, &prompt);
        index++;
    }
}