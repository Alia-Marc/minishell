/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_within_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:43:21 by emilefourni       #+#    #+#             */
/*   Updated: 2024/09/26 21:58:41 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int is_char_in_quotes(char *str, int index)
{
    int i;
    bool quotesOpen;

    i = 0;
    quotesOpen = false;
    while (i <= index)
    {
        if (str[i] == 34 || str[i] == 39)
            quotesOpen = !quotesOpen;
        i++;
        if (quotesOpen && i == index)
            return (1);
    }
    return (0);
}
