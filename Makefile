NAME =  push_swap.out
SRC =  *.c
OBJ = $(patsubst %c,%o,$(wildcard $(SRC)))
RM = libft.a $(NAME)
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJ) libft.a
	cc $(CFLAGS) $^ libft.a
libft.a:
	(cd libft && make aclean && mv libft.a ..)
# main: $(NAME) libft.h main.o
# 	cc $(CFLAGS) -lbsd main.o -L . -l ft
%.o: %.c libft.a
	cc -c $(CFLAGS) $< -L . -l ft
clean:
	rm -f *.o
fclean: clean
	rm -f $(wildcard $(RM))
re: fclean all
.PHONY: all clean fclean re main