/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/07/25 11:31:40 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char *argv[])
{
    argc = 1;
    printf("%d\n", pipe_checker(argv[argc]));
    return 0;
}


/*int    main(void)
{
    char    *line;

    while (1)
    {
        line = readline("");
        printf("%d", pipe_checker(line));
        free(line);
    }
    return (0);
}*/
