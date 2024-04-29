CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS = src/minishell.c \
       src/setup_env.c \
       src/utilsv1.c \
       src/parsing.c \
       src/quotes.c \
       src/utilsv2.c \
       src/nbr_quotes.c

OBJS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME = minishell

$(NAME): $(OBJS)
	@make -C LIBFT/
	$(CC) $(CFLAGS) $^ -o $@ LIBFT/libft.a -lreadline

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)

clean:
	@make fclean -C LIBFT/
	rm -f $(OBJS)

fclean: clean
	@make fclean -C LIBFT/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
