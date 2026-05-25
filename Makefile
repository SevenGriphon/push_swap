NAME     = push_swap
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g

SRCS     = main.c \
           operations.c \
           push_swap_algorithe1.c \
           push_swap_algorithe2.c \
           push_swap_adaptive.c \
		   binary_radix.c \
		   radix_utils.c \
		   math.c \

OBJS     = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF     = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

aclean: all clean

re: fclean all

.PHONY: all clean fclean aclean re
