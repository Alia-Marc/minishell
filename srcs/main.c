/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:54:18 by malia             #+#    #+#             */
/*   Updated: 2024/07/19 14:45:33 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int    main(void)
{
    char    *line;

    while (1)
    {
        line = readline("");
        printf("%d", quotes_handler(line));
        free(line);
    }
    return (0);
}
