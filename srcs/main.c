/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/08/24 16:56:47 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parsing.h"

// void    print_list(t_file *file)
// {
//     t_file *tmp_file;

//     tmp_file = file;
//     while (tmp_file->next)
// 	{
//         printf("file name : %s\nfile mode : %d\n", tmp_file->file, tmp_file->mode);
// 		tmp_file = tmp_file->next;
//         if (!tmp_file->next)
//         {
//             printf("file name : %s\nfile mode : %d\n", tmp_file->file, tmp_file->mode);
//             break ;
//         }
// 	}
// }

// int main(int argc, char *argv[])
// {
//     t_prompt	*prompt;

//     prompt = malloc(sizeof(t_prompt));
//     prompt->file = NULL;
//     prompt->next = NULL;
// 	// prompt->file = malloc(sizeof(t_list));
//     printf("is valid : %d\n", redirect_handler(argv[1], prompt));
//     print_list(prompt->file);
// 	free_prompt(&prompt);
//     return (argc);
// }

// int main(int argc, char *argv[])
// {
//     printf("%d\n", ft_lexer(argv[1]));
//     return argc;
// }


int    main(void)
{
    char    *line;
    t_prompt    *prompt;

    prompt = NULL;
    while (1)
    {
        line = readline("");
        printf("%d\n", ft_lexer(line));
    }
    return (0);
}
