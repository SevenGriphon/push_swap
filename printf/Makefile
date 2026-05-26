NAME =  libftprintf.a
SRC =  utils.c formating.c ft_printf.c ft_itoa.c
OBJ = $(patsubst %c,%o,$(SRC))
RM = libft.a $(NAME) a.out
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs ${NAME} $^
%.o: %.c
	cc -c $(CFLAGS) $^
main: $(NAME) main.o
	cc $(CFLAGS) main.o -L . -l ftprintf
clean:
	rm -f *.o
fclean: clean
	rm -f $(wildcard $(RM))
aclean: all clean
re: fclean all
.PHONY: all clean fclean re aclean main