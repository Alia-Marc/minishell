NAME = minishell

NAME_BONUS = minishell_bonus

LIBFT = ./libft

INCLUDE = /include/minishell.h

SRC = srcs/exec/exec.c srcs/exec/path.c srcs/exec/fake_inits.c \

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
