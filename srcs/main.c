/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/09/11 17:09:26 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/parsing.h"

// int main(int argc, char *argv[])
// {
// 	t_prompt	*prompt;

// 	prompt = NULL;
// 	prompt = prompt_init(prompt);
// 	prompt = ft_filler(argv[1], prompt);
//     return argc;
// }

int    main(void)
{
    char    *line;
	t_prompt	*prompt;

	prompt = NULL;
    while (1)
    {
        line = readline("");
		if (ft_checker(line))
		{
			prompt = prompt_init(prompt);
			prompt = ft_filler(line, prompt);
			// free_prompt(&prompt, line);
		}
    }
    return (0);
}

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


