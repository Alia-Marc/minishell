/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/09/16 17:40:10 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parsing.h"

// int main(int argc, char *argv[])
// {
// 	t_prompt	*prompt;

// 	prompt = NULL;
// 	prompt = prompt_init();
// 	prompt = ft_filler(argv[1], prompt);
// 	free_prompt(&prompt);
// 	free(prompt);
//     return argc;
// }

void	printf_prompt(t_prompt *prompt);
void	print_files(t_prompt *prompt);
void	free_prompt1(t_prompt **prompt);

int main(int argc, char *argv[])
{
	t_prompt	*prompt;

	prompt = NULL;
	if (ft_checker(argv[1]))
	{
		prompt = prompt_init();
		prompt = ft_filler(argv[1], prompt);
		printf_prompt(prompt);
		free_prompt1(&prompt);
		free(prompt);;
	}
	return argc;
}


// int    main(void)
// {
//     char    *line;
// 	t_prompt	*prompt;

// 	prompt = NULL;
//     while (1)
//     {
//         line = readline("");
// 		if (ft_strcmp(line, "caca") == 0)
// 		{
// 			free(line);
// 			break ;
// 		}

// 		if (ft_checker(line))
// 		{
// 			prompt = prompt_init();
// 			prompt = ft_filler(line, prompt);

// 			free(line);
// 			printf_prompt(prompt);
// 			free_prompt1(&prompt);
// 		}
//     }
//     return (0);
// }

void	free_prompt1(t_prompt **prompt)
{
	t_prompt	*tmp;

	if (!prompt)
		return ;
	while (*prompt)
	{
		tmp = (*prompt)->next;
		free_file(&(*prompt)->file);
		ft_free_tab((*prompt)->cmd);
		if ((*prompt)->path)
			free((*prompt)->path);
		free(*prompt);
		*prompt = tmp;
	}
}

void	printf_prompt(t_prompt *prompt)
{
	int i = 0;
	int j = 0;
	t_prompt *tmp_prompt;

	tmp_prompt = prompt;
	while (tmp_prompt)
	{
		i = 0;
		ft_printf("\nprompt[%d]\n", j);
		ft_printf("prompt->cmd : ");
		while (tmp_prompt->cmd && tmp_prompt->cmd[i])
		{
			ft_printf("%s, ", tmp_prompt->cmd[i]);
			i++;
		}
		ft_printf("\n");
		print_files(tmp_prompt);
		j++;
		tmp_prompt = tmp_prompt->next;
	}
	ft_printf("\n");
}

void	print_files(t_prompt *prompt)
{
	t_file *tmp_file;
	int 	i = 0;

	tmp_file = prompt->file;
	while (tmp_file)
	{
		ft_printf("file[%d] = name : %s mode : %d\n", i, tmp_file->file, tmp_file->mode);
		tmp_file = tmp_file->next;
		i++;
	}
}

// int    main(void)
// {
//     char    *line;
// 	t_prompt	*prompt;

// 	prompt = NULL;
//     while (1)
//     {
//         line = readline("");
// 		if (ft_checker(line))
// 		{
// 			prompt = prompt_init(prompt);
// 			prompt = ft_filler(line, prompt);
// 			free_prompt(&prompt);
// 			free(prompt);
// 		}
//     }
//     return (0);
// }

// int main(int argc, char *argv[])
// {
// 	// t_prompt	*prompt;

// 	// prompt = NULL;
// 	// prompt = prompt_init(prompt);
//     // if (ft_checker(argv[1]))
//     //     ft_filler(argv[1], prompt);
//     char **split;

//     split = NULL;
//     split = split_cmd(argv[1], ' ');
//     print_split(split, argv[1]);
//     printf("\n%zu\n", ft_countword(argv[1], ' '));
// 	// free_cmd(split);
//     return argc;
// }

// int main(int argc, char *argv[])
// {
// 	printf("%d\n", quotes_handler(argv[1]));
// 	return argc;
// }


