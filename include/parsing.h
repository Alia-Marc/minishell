/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:16:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 14:48:03 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

//quotes_handler.c

int	double_quote_closed(char *str);
int	single_quote_closed(char *str);
bool within_double_quote(char *str, size_t index);
int within_single_quote(char *str, size_t index);

//parsing.c

t_prompt	ft_lexer(char *cmd_line);

#endif
