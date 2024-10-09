/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:16:09 by emfourni          #+#    #+#             */
/*   Updated: 2024/10/09 20:02:17 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "minishell.h"
# include "error.h"

///////////////////////////////////////////////////////QUOTES HANDLING

//quotes_handler.c

int			quotes_handler(char *cmd_line);
int			double_quote_closed(char *str);
int			single_quote_closed(char *str);

//true_within_quotes.c

int			is_char_in_quotes(char *str, int index);
int			is_char_in_double_quotes(char *str, int index);
int			is_char_in_single_quotes(char *str, int index);
int			is_char_in_single_quotes_expand(char *str, int index);

///////////////////////////////////////////////////////SYNTAX CHECKER

//check_styntax.c

int			check_syntax(char *cmd_line);

//pipe_checker.c

int			pipe_checker(char *cmd_line);
bool		ft_rev_indexwhitespace(char *str, int index);
bool		ft_indexwhitespace(char *str, int index);
int			ft_isspaceorpipe(char c);

//redirect_checker.c

int			redirect_checker(char *cmd_line);
int			ft_is_redirect(char c);
int			nb_redirect(char *str);
int			check_parenthesis(char *str);
int			check_empty_name(char *str);

//redirect_checker2.c

int			ft_dollarsign_redirect(char *file);
int			space_between_cmd_redirect(char *cmd_line);

//////////////////////////////////////////////////////STRUCT_FILLER

//cmd_handler.c

void		cmd_handler(char *cmd_line, t_prompt *prompt, t_exec *exec);

//split_cmd.c

char		**split_cmd(char *cmd_line, char c);

//split_cmd_utils.c

int			redirect_skip(char *s, int j, char c);
int			check_for_cmd(char *s, int index, char c);
void		copy_everything(char *s, char *tab, int *j, int *t);
char		*tab_alloc(char **tab, int index_string, int index_char);

//split_pipes.c

char		**split_cmd_pipe(char *s, char c, int i);
void		end_tab(char **tab, int *i, bool seen_redirect, int t);

//redirection_handlers.c

void		redirect_handler(char *cmd_line, t_prompt *prompt);
void		redirect_filler(char *line, int index, t_prompt *prompt, int mode);
void		skip_in_quotes(char *str, int *i);

//redirection_utils.c

t_file		*create_new_file(char *file, int mode);
t_file		*filelast(t_file *file);
void		fileadd_back(t_file **file, t_file *new);
void		free_file(t_file **file);
char		*ft_strdupnospace(char *str, int index);
int			is_in_redirect(char *s, int index, int max_index);

//skip_or_no_skip.c

void		skip_or_no_skip(char *s, int *j, int *t, char c);

////////////////////////////////////////////////////////PARSING

char		*expand_var(t_exec *exec, char *line);
int			expanded_len(t_exec *exec, char *line);
int			len_potential_var(char *line, int i);
char		*expanded_var(t_exec *exec, char *name, int len_var);

//parsing.c

int			ft_checker(char *cmd_line);
t_prompt	*ft_filler(char *cmd_line, t_prompt *prompt, t_exec *exec);

//parsing_utils.c

bool		ft_is_metachar(char c);
t_prompt	*prompt_init(void);
t_prompt	*promptlast(t_prompt *prompt);
void		promptadd_back(t_prompt **prompt, t_prompt *new);

#endif
