CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap.a
OUT=push_swap
BONUS_OUT=checker

FILES=push.c swap.c rotate.c r_rotate.c get_pivot.c best_path.c easy_sort.c sort_in_group.c epic_checks.c sorting_core.c get_things.c move_things.c  epic_part.c get_input.c
BONUS=checker/checker.c
OBJECTS=$(FILES:.c=.o)
BONUS_OBJS=$(BONUS:.c=.o)

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

bonus: all
	$(CC) $(CFLAGS) checker.c $(NAME) -o $(BONUS_OUT)

.PHONY:	all clean fclean re
