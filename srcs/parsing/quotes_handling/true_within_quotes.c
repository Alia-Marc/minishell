/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_within_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:43:21 by emilefourni       #+#    #+#             */
/*   Updated: 2024/09/24 11:50:44 by emfourni         ###   ########.fr       */
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
