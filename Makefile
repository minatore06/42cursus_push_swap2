CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap.a
OUT=push_swap

FILES=push.c swap.c rotate.c r_rotate.c get_pivot.c best_path.c
OBJECTS=$(FILES:.c=.o)

LIBFT=libft/
LIBFTNAME=libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) bonus -C $(LIBFT)
	mv $(LIBFT)$(LIBFTNAME) $(NAME)
	ar rcs $(NAME) $(OBJECTS)
	$(CC) $(CFLAGS) push_swap.c $(NAME) -o $(OUT)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)$(LIBFTNAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
