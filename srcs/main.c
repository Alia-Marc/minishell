/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/07/31 16:49:09 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    print_list(t_file *file)
{
    while (file->next)
	{
        printf("file name : %s\nfile mode : %d\n", file->file, file->mode);
		file = file->next;
        if (!file->next)
        {
            printf("file name : %s\nfile mode : %d\n", file->file, file->mode);
            break ;
        }
	}
}

int main(int argc, char *argv[])
{
    t_prompt	*prompt;

    prompt = malloc(sizeof(t_prompt));
	// prompt->file = malloc(sizeof(t_list));
    printf("is valid : %d\n", redirect_handler(argv[1], prompt));
    print_list(prompt->file);
    // free(prompt->file->file);
	free(prompt->file);
	free(prompt);
    return (argc);
}


// int    main(void)
// {
//     char    *line;
//     t_prompt    *prompt;

//     prompt = NULL;
//     while (1)
//     {
//         line = readline("");
//         printf("infile handler : %d\n file name : %s", redirect_checker(line, prompt), prompt->file->file);
//         free(line);
//     }
//     return (0);
// }
