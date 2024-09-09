/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/09/09 13:14:24 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parsing.h"

// int main(int argc, char *argv[])
// {
//     t_prompt	*prompt;

//     prompt = malloc(sizeof(t_prompt));
//     prompt->file = NULL;
//     prompt->next = NULL;
// 	// prompt->file = malloc(sizeof(t_list));
//     redirect_handler(argv[1], prompt);
//     print_list(prompt->file);
// 	free_prompt(&prompt);
//     return (argc);
// }

// int main(int argc, char *argv[])
// {
//     printf("%d\n", ft_checker(argv[1]));
//     return argc;
// }


// int    main(void)
// {
//     char    *line;
//     t_prompt    *prompt;

//     prompt = NULL;
//     while (1)
//     {
//         line = readline("");
//         printf("%d\n", ft_checker(line));
//     }
//     return (0);
// }

int main(int argc, char *argv[])
{
    ft_filler(argv[1]);
    return argc;
}

