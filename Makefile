CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
CHECK_NAME=checker

FILES=push_swap.c push.c swap.c rotate.c r_rotate.c get_pivot.c check_order.c best_path.c easy_sort.c trio_in_group.c four_in_group.c five_in_group.c epic_checks.c sorting_core.c get_things.c move_things.c  epic_part.c get_input.c free_stack.c
BONUS=check/learn_and_do.c check/checker.c push.c swap.c rotate.c r_rotate.c get_input.c check_order.c free_stack.c
OBJECTS=$(FILES:.c=.o)
BONUS_OBJS=$(BONUS:.c=.o)

LIBFT=libft/
LIBFTNAME=libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT)$(LIBFTNAME) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME) $(CHECK_NAME)

re:	fclean $(NAME)

bonus: $(BONUS_OBJS)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT)$(LIBFTNAME) -o $(CHECK_NAME)

.PHONY:	all clean fclean re
