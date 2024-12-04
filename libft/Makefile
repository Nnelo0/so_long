NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstclear_bonus.c \
	libft/ft_lstdelone_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstmap_bonus.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstsize_bonus.c \
	libft/ft_lstiter_bonus.c \
	printf/ft_printf.c \
	printf/printf_char.c \
	printf/printf_digit.c \
	printf/printf_hex.c \
	printf/printf_ptr.c \
	printf/printf_string.c \
	printf/printf_udigit.c \
	gnl/get_next_line.c \

AR = ar rcs

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) $(NAME) *.o
	@rm -f *.o
	@echo "Library $(NAME) successfully created!"

clean:
	@echo "No .o files to clean in this version."

fclean: clean
	$(RM) $(NAME)

re: fclean all
