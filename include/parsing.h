/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:16:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 18:03:39 by emfourni         ###   ########.fr       */
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

//QUOTES HANDLING

//quotes_handler.c

int	quotes_handler(char *cmd_line);
int	double_quote_closed(char *str);
int	single_quote_closed(char *str);

//within_quotes.c

int within_double_quote(char *str, size_t index);
int within_single_quote(char *str, size_t index);
size_t	get_first_pos_quote(char *str, char c);
size_t	get_last_pos_quote(char *str, char c);

//SYNTAX CHECKER

//pipe_checker.c

int	pipe_checker(char *cmd_line);

//redirection_checker.c

//parsing.c

bool	ft_iswhitespace(char *str, int index);
bool	ft_rev_iswhitespace(char *str, int index);

// t_prompt	ft_lexer(char *cmd_line);

#endif
