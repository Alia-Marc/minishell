/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:14:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/07/19 16:15:52 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include "../libft/libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

// error_msg.h

void	ft_error_empty_cmd_line(void);
void	ft_quote_error(void);
void	ft_syntax_error(void);


#endif
