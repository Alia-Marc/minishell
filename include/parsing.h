/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:16:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/09/17 15:28:26 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "minishell.h"
# include "stdlib.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

///////////////////////////////////////////////////////QUOTES HANDLING

//quotes_handler.c

int				quotes_handler(char *cmd_line);
int				double_quote_closed(char *str);
int				single_quote_closed(char *str);

//within_quotes.c

int				within_double_quote(char *str, size_t index);
int				within_single_quote(char *str, size_t index);

//within_quotes_split.c

int				within_single_quote2(char *str, int index);
int				within_double_quote2(char *str, int index);


//within_quotes_pipe.c

int				within_single_quote_pipe(char *str, int index);
int				within_double_quote_pipe(char *str, int index);



///////////////////////////////////////////////////////SYNTAX CHECKER

//check_styntax.c

int				check_syntax(char *cmd_line);

//pipe_checker.c

int				pipe_checker(char *cmd_line);
bool			ft_rev_indexwhitespace(char *str, int index);
bool			ft_indexwhitespace(char *str, int index);
int				ft_isspaceorpipe(char c);

//redirect_checker.c

int				redirect_checker(char *cmd_line);
int				ft_is_redirect(char c);
int				ft_dollarsign_redirect(char *file);
int				nb_redirect(char *str);
int				check_parenthesis(char *str);
int				check_empty_name(char *str);

//////////////////////////////////////////////////////STRUCT_FILLER

//cmd_handler.c

void			cmd_handler(char *cmd_line, t_prompt *prompt);

//cmd_utils.c

char			**split_cmd(char *cmd_line, char c);
void			free_cmd(char **split);
int				ft_countword(char *str, char c);

//cmd_utils.c

char			**split_cmd_pipe(char *s, char c);

//redirection_handlers.c

void			redirect_handler(char *cmd_line, t_prompt *prompt);
void			redirect_filler(char *line, int index, t_prompt *prompt, int mode);

//redirection_utils.c

t_file			*create_new_file(char *file, int mode);
t_file			*filelast(t_file *file);
void			fileadd_back(t_file **file, t_file *new);
void			free_file(t_file **file);
char			*ft_strdupnospace(char *str, int index);

////////////////////////////////////////////////////////PARSING

//parsing.c

int				ft_checker(char *cmd_line);
t_prompt		*ft_filler(char *cmd_line, t_prompt *prompt);

//parsing_utils.c

void			free_prompt(t_prompt **prompt);
bool			ft_is_metachar(char c);
t_prompt		*prompt_init(void);
t_prompt		*promptlast(t_prompt *prompt);
void			promptadd_back(t_prompt **prompt, t_prompt *new);

#endif
