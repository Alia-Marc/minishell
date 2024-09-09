/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:28:02 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/09 17:15:24 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ft_countpipes(char *str)
{
	int	index;
	int	pipe;

	index = 0;
	pipe = 0;
	while (str[index])
	{
		if (str[index] == '|')
			pipe++;
		index++;
	}
	return (pipe + 1);
}

void	print_cmd(t_prompt *prompt)
{
	int	word;

	word = 0;
	while (word < 2)
	{
		printf("prompt->cmd : %s\n", prompt->cmd[word]);
		word++;
	}
}

void	print_list(t_prompt *prompt)
{
	while (prompt)
	{
		print_cmd(prompt);
		prompt = prompt->next;
	}
}

void	free_split(char **split, char *cmd_line)
{
	int	index;

	index = 0;
	while (index < ft_countpipes(cmd_line))
	{
		free(split[index]);
		index++;
	}
	free(split);
}

void	print_split(char **split, int nb_cmd)
{
	int index;

	index = 0;
	while (index < 3)
	{
		printf("%drd prompt->cmd : %s ", index + 1, split[index]);
		index++;
	}
	printf("\n");
	printf("NODE NUMBER : %d\n", nb_cmd);
}

void	cmd_handler(char *cmd_line, t_prompt *prompt)
{
	int	index;
	char **cmd_split;
	int nb_pipes = ft_countpipes(cmd_line);

	index = 0;
	cmd_split = ft_split(cmd_line, '|');
	while (index < nb_pipes)
	{
		prompt->cmd = ft_split(cmd_split[index], ' ');
		print_split(prompt->cmd, index);
		promptadd_back(&prompt, prompt_init(prompt));
		redirect_handler(cmd_split[index], prompt);
		index++;
	}
	free_split(cmd_split, cmd_line);
}
