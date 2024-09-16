NAME = minishell

NAME_BONUS = minishell_bonus

LIBFT = ./libft

INCLUDE = /include/minishell.h

SRC =	srcs/main.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/quotes_handling/quotes_handler.c \
		srcs/parsing/quotes_handling/within_quotes.c \
		srcs/parsing/quotes_handling/within_quotes_split.c \
		srcs/parsing/quotes_handling/within_quotes_pipe.c \
		srcs/parsing/syntax_checker/check_syntax.c \
		srcs/parsing/syntax_checker/pipe_checker.c \
		srcs/parsing/syntax_checker/redirect_checker.c \
		srcs/parsing/syntax_checker/redirect_checker2.c \
		srcs/parsing/struct_filler/redirect_handler.c \
		srcs/parsing/struct_filler/redirect_utils.c \
		srcs/parsing/struct_filler/cmd_handler.c \
		srcs/parsing/struct_filler/cmd_utils.c \
		srcs/parsing/struct_filler/cmd_utils2.c \
		srcs/error/error_msg.c \
		srcs/error/error_msg2.c \

FLAGS = -Wall -Wextra -Werror

$(NAME):    $(SRC)
			make --silent -C $(LIBFT)
			cc  $(FLAGS) $(SRC) -I $(INCLUDE) -lreadline $(LIBFT)/libft.a -o $(NAME) -g3

$(NAME_BONUS):    $(SRC_BONUS)
			      make --silent -C $(LIBFT)
			      cc  $(FLAGS) $(SRC_BONUS) -I $(INCLUDE_BONUS) $(LIBFT)/libft.a -o $(NAME_BONUS)
all:    $(NAME)

bonus:  $(NAME_BONUS)

clean:
		rm -f $(NAME) $(NAME_BONUS)

fclean:    clean
		make --silent fclean -C $(LIBFT)

re:    fclean all
