NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRCS = SRCS/main.c SRCS/check_map.c SRCS/error.c SRCS/map.c SRCS/move_player.c \

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) -I. -I$(LIBFTDIR) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re