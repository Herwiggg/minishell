CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS = minishell.c utilsv1.c setup_env.c cd.c env.c

OBJS = $(SRCS:.c=.o)

NAME = minishell

$(NAME): $(OBJS)
	@make -C libft42/
	@make -C ft_printf/
	$(CC) $(CFLAGS) $^ -o $@ libft42/libft.a ft_printf/libftprintf.a -lreadline

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)

clean:
	@make fclean -C libft42/
	@make fclean -C ft_printf/
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft42/
	@make fclean -C ft_printf/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re