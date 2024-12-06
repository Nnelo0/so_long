NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRCS = SRCS/main.c SRCS/check_map.c SRCS/error.c SRCS/map.c SRCS/move_player.c SRCS/utils.c \

BONUS =	SRCS_bonus/main.c SRCS_bonus/check_map.c SRCS_bonus/error.c SRCS_bonus/map.c \
		SRCS_bonus/move_player.c SRCS_bonus/check_map_utils.c SRCS_bonus/move_player_utils.c \

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) -I. -I$(LIBFTDIR) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS) $(LIBFT)
	$(CC) -I. -I$(LIBFTDIR) $(BONUS) $(LIBFT) $(CFLAGS) -o $(NAME_BONUS)
	@echo "Compiled $(NAME_BONUS) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re