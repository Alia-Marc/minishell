/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:14:28 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/18 20:27:45 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

// error_msg.h

void	ft_error_empty_cmd_line(void);
void	ft_quote_error(void);
void	ft_syntax_error(void);
void	ft_redirect_name_empty(void);
void	ft_metachar_near_token(void);

// error_msg2.c

void	ft_bad_pipe_msg(void);
void	too_many_redirect(void);

#endif
