NAME = minishell

LIBFT = ./libft

INCLUDE = /include/minishell.h

EXEC = srcs/exec/exec.c srcs/exec/path.c srcs/exec/redirection.c \
		srcs/exec/pipe_handling.c srcs/exec/utils.c srcs/exec/free_structs.c \
		srcs/exec/here_doc.c srcs/exec/builtins_handling.c srcs/exec/builtins/pwd.c \
		srcs/exec/builtins/echo.c srcs/exec/builtins/env.c srcs/exec/builtins/cd.c \
		srcs/exec/builtins/init_local_env.c srcs/exec/builtins/export.c srcs/exec/builtins/export_utils.c \
		srcs/exec/builtins/sort_env.c srcs/exec/builtins/unset.c srcs/exec/builtins/exit.c \
		srcs/exec/init_exec.c \

PARSING = srcs/parsing/expand_var.c srcs/parsing/expand_var_len.c \
		srcs/parsing/parsing.c srcs/parsing/parsing_utils.c srcs/parsing/quotes_handling/quotes_handler.c \
		srcs/parsing/quotes_handling/true_within_quotes.c \
		srcs/parsing/syntax_checker/check_syntax.c srcs/parsing/syntax_checker/pipe_checker.c \
		srcs/parsing/syntax_checker/redirect_checker.c srcs/parsing/syntax_checker/redirect_checker2.c \
		srcs/parsing/struct_filler/redirect_handler.c srcs/parsing/struct_filler/redirect_utils.c \
		srcs/parsing/struct_filler/cmd_handler.c srcs/parsing/struct_filler/split_cmd.c \
		srcs/parsing/struct_filler/split_pipes.c srcs/error/error_msg.c srcs/error/error_msg2.c \
		srcs/parsing/struct_filler/split_cmd_utils.c srcs/parsing/struct_filler/skip_or_no_skip.c \


SIGNAL = srcs/signal/signal.c srcs/signal/signal_cmd.c

FLAGS = -Wall -Wextra -Werror -g3

$(NAME):    $(EXEC) $(PARSING) $(SIGNAL) srcs/main.c
			make --silent -C $(LIBFT)
			cc  $(FLAGS) $(EXEC) $(PARSING) $(SIGNAL) srcs/main.c -I $(INCLUDE) -lreadline $(LIBFT)/libft.a -o $(NAME)

all:    $(NAME)

bonus:  $(NAME_BONUS)

clean:
		rm -f $(NAME) $(NAME_BONUS)

fclean:    clean
		make --silent fclean -C $(LIBFT)

re:    fclean all
