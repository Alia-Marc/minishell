/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:28:02 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/13 16:31:44 by marc             ###   ########.fr       */
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

// void	print_split(char **split, int nb_cmd)
// {
// 	int index;

// 	index = 0;
// 	while (index < nb_cmd)
// 	{
// 		printf("%dRD PROMPT->CMD : %s ", index + 1, split[index]);
// 		index++;
// 	}
// 	printf("\n");
// }

// void	cmd_handler(char *cmd_line, t_prompt *prompt)
// {
// 	int	index;
// 	char **cmd_split;
// 	int nb_pipes;

// 	index = 0;
// 	nb_pipes = ft_countpipes(cmd_line);
// 	cmd_split = ft_split(cmd_line, '|');
// 	while (index < nb_pipes)
// 	{
// 		// printf("NODE NUMBER : %d\n", index);
// 		prompt->cmd = split_cmd(cmd_split[index], ' ');
// 		promptadd_back(&prompt, prompt_init(prompt));
// 		// print_split(prompt->cmd, ft_countword(cmd_split[index], ' '));
// 		redirect_handler(cmd_split[index], prompt);
// 		prompt = prompt->next;
// 		index++;
// 	}
// 	free_cmd(cmd_split);
// }


void	cmd_handler(char *cmd_line, t_prompt *prompt)
{
	int			index;
	char		**cmd_split;
	int			nb_pipes;

	index = 0;
	nb_pipes = ft_countpipes(cmd_line);
	cmd_split = ft_split(cmd_line, '|');
	while (index < nb_pipes)
	{
		prompt->cmd = split_cmd(cmd_split[index], ' ');
		redirect_handler(cmd_split[index], prompt);
		index++;
		if (index < nb_pipes)
			promptadd_back(&prompt, prompt_init());
		prompt = prompt->next;
	}
	//free_cmd(cmd_split, nb_pipes); ta fonction est claque ca free meme pas, utilise just un free tab normal zebi
	ft_free_tab(cmd_split);
}
