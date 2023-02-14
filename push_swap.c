/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:59 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 14:33:02 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//22 24 12 7 14 16 3 15 17 19 9 18 25 6 10 8 23 11 20 5 21 1 4 13 2 
void	print_stack(t_stack *s)
{
	while (s)
	{
		//ft_printf("%d|", s->x);
		if (s->right)
			//ft_printf("\\/");
		//ft_printf("\n");
		s = s->next;
	}
	//ft_printf("A\n");
}

int	ft_abs(int	x)
{
	if (x < 0)
		x = -x;
	return (x);
}

t_stack *manage_input(char **argv)
{
	t_stack	*input;
	int	n;
	int	i;
	int	j;

	input = 0;
	i = 1;
	while (argv[i])
	{
		j= 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				break ;
			j++;
		}
		if (j != ft_strlen(argv[i]))
			return (input);
		n = ft_atoi(argv[i]);
		ft_lstadd_back(&input, ft_lstnew(n));
		i++;
	}
	return (input);
}

void	move_to_b(t_stack **A, t_stack **B, t_stack *el, int verbose)
{
	//if (verbose)
		//ft_printf("Sto spostando in b %d\n", el->x);
	put_first(A, el, verbose, 1);
	pb(A, B, verbose);
}

void	move_to_a(t_stack **A, t_stack **B, t_stack *el, int verbose)
{
	//if (verbose)
		//ft_printf("Sto spostando in a %d\n", el->x);
	put_first(B, el, verbose, 0);
	pa(A, B, verbose);
}

void	move_smallers(t_stack **A, t_stack **B, t_stack *pivot, int direction)
{
	t_stack	*el;

	el = *A;
	while(el)
	{
		if (el->x < pivot->x)
		{
			if (direction == 1)
				move_to_a(A, B, el, 1);
			else if (direction == -1)
				move_to_b(A, B, el, 1);
			el = *A;
			continue ;
		}
		el = el->next;
	}
	if (direction == 1)
		move_to_a(A, B, pivot, 1);
	else if (direction == -1)
		move_to_b(A, B, pivot, 1);
}

void	move_largers(t_stack **A, t_stack **B, t_stack *pivot, int direction)
{
	t_stack	*el;

	el = *B;
	while(el)
	{
		if (el->x > pivot->x)
		{
			if (direction == 1)
				move_to_a(A, B, el, 1);
			else if (direction == -1)
				move_to_b(A, B, el, 1);
			el = *B;
			continue ;
		}
		el = el->next;
	}
	if (direction == 1)
		move_to_a(A, B, pivot, 1);
	else if (direction == -1)
		move_to_b(A, B, pivot, 1);
	pivot->right = 1;
}

void	swap2el(t_stack **A, t_stack **B, t_stack *el1, t_stack *el2)
{
	t_stack	*go_first;

	if (get_next(*A, el1) == el2)
	{
		put_first(A, el1, 1, 1);
		sa(A, 1);
		return;
	}
	go_first = get_next(*A, el1);
	move_to_b(A, B, el1, 1);
	move_to_b(A, B, el2, 1);
	//print_stack(*A);
	sb(B, 1);
	pa(A, B, 1);
	put_first(A, go_first, 1, 1);
	pa(A, B, 1);
	//print_stack(A.head);
}

void	swap_pivot(t_stack **A, t_stack **B, t_stack *last, t_stack *el2)
{
	t_stack	*go_first;

	go_first = get_next(*A, last);
	if (go_first == el2)
		go_first = get_next(*A, el2);
	if (!go_first)
	{
		//ft_printf("sos\n");
		go_first = *A;
	}
	move_to_b(A, B, el2, 1);
	//print_stack(*A);
	sb(B, 1);
	pa(A, B, 1);
	put_first(A, go_first, 1, 1);
	pa(A, B, 1);
	//print_stack(A.head);
}

t_stack	*get_first_bigger(t_stack *lst, t_stack *start, int pivot)
{
	int		size;

	size = ft_lstsize(lst);
	while (size--)
	{
		////ft_printf("%d\n", lst->x);
		if (start->x > pivot && !start->right)
			return (start);
		start = get_next(lst, start);
	}
	return (0);
}

t_stack	*get_last_smaller(t_stack *lst, t_stack *start, int pivot)
{
	t_stack	*small;
	int		size;
	int		i;

	size = ft_lstsize(lst) - 1;
	while (size >= 0)
	{
		small = start;
		i = 0;
		while (size - i++)
			small = get_next(lst, small);
		size--;
		if (small->x < pivot && !small->right)
			return (small);
	}
	return (0);
}

t_stack	*get_smaller(t_stack *A)
{
	t_stack	*min;

	min = A;
	while (A)
	{
		if (A->x < min->x)
			min = A;
		A = A->next;
	}
	return (min);
}

t_stack	*get_bigger(t_stack *A)
{
	t_stack	*max;

	max = A;
	while (A)
	{
		if (A->x > max->x)
			max = A;
		A = A->next;
	}
	return (max);
}

int	left_is_right(t_stack *lst, t_stack *start, t_stack *big, t_stack *small)
{
	//ft_printf("small: %d, big: %d\n", small->x, big->x);
	if (small == start)
		return (1);
	while (small != start)
	{
		if (small == big)
			return (1);
		small = get_next(lst, small);
	}
	return (0);
}

int	is_order(t_stack *lst, t_stack *start, t_stack *end)
{
	int	old;

	old = start->x;
	start = get_next(lst, start);
	while (start != end)
	{
		//ft_printf("hello\n");
		if (old > start->x)
			return (0);
		old = start->x;
		start = get_next(lst, start);
	}
	return (1);
}

void	middle_sort(t_stack **A, t_stack **B, t_stack *start, int count)
{
	t_stack *pivot;

	put_first(A, start, 1, 1);
	while (count--)
		pb(A, B, 1);
	pivot = get_pivot(*B, get_smaller(*B), get_bigger(*B));
	divide_et_impera(A, B, pivot);
	//ft_printf("MEGA\n");
	epic_check(A, B);
}

void	epic_check(t_stack **A, t_stack **B)
{
	t_stack	*lst;
	t_stack	*first;
	t_stack	*second;

	lst = *A;
	while (lst)
	{
		if (lst->right)
		{
			lst = consecutive_numbers(*A, lst, 0);
			first = lst;
			lst = lst->next;
			while (lst)
			{
				if (lst->right)
				{
					second = lst;
					second = consecutive_numbers(*A, second, 1);
					//ft_printf("first %d, second %d\n", first->x, second->x);
					if (get_distance(*A, first, second) == 1){//ft_printf("alone\n");
						alone_numbers(get_next(*A, first));}
					else if (get_distance(*A, first, second) == 2){//ft_printf("couple\n");
						couple_numbers(A, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 3){//ft_printf("trio\n");
						trio_in_group(A, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 4){//ft_printf("quadro\n");
						four_in_group(A, B, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 5){//ft_printf("quinto\n");
						five_in_group(A, B, get_next(*A, first));}
					else{//ft_printf("picche\n");
						middle_sort(A, B, get_next(*A, first), get_distance(*A, first, second));}
					lst = second;
					break ;
				}
				lst = lst->next;
			}
			//print_stack(*A);
			
		}
		else
			lst = lst->next;
	}
}
//MOVE ALL SMALLER TO B
//MOVE PIVOT TO B
//PUT larger then next pivot
//again
//again
void	sort(t_stack **A, t_stack **B)
{
	t_stack *pivot;
/* 	t_stack	*big_left;
	t_stack	*small_right; */

/* 	if (is_order(A->head, first, last))
		return ; */
	////ft_printf("bfr last %p\n", last);
	pivot = get_pivot(*A, get_smaller(*A), get_bigger(*A));
	//ft_printf("size: %d, pivot %d\n",ft_lstsize(*A), pivot->x);
	move_smallers(A, B, pivot, -1);
	pa(A, B, 1);
	pivot->right = 1;
	divide_et_impera(A, B, pivot);
	//ft_printf("MEGA\n");
	epic_check(A, B);
	/* if (get_distance(A->head, first, pivot) == 2)
	{
		//ft_printf("21\n");
		small_right = bfrthis(A->head, pivot);
		if (bfrthis(A->head, small_right)->x > small_right->x)
			swap2el(&A->head, B, bfrthis(A->head, small_right), small_right);
		else
		{
			small_right->right = 1;
			bfrthis(A->head, small_right)->right = 1;
		}
	}
	else if (get_distance(A->head, first, pivot) == 1){
		//ft_printf("?\n");
		bfrthis(A->head, pivot)->right = 1;}
	else{
		//ft_printf("REDO1 %d\n", pivot->x);
		sort(A, B, first, pivot);}
	if (get_distance(A->head, pivot, bfrthis(A->head, last)) == 2)
	{
		//ft_printf("22\n");
		pivot = get_next(A->head, pivot);
		if (pivot->x > get_next(A->head, pivot)->x)
			swap2el(&A->head, B, pivot, get_next(A->head, pivot));
		else
		{
			pivot->right = 1;
			get_next(A->head, pivot)->right = 1;
		}
	}
	else if (get_distance(A->head, pivot, bfrthis(A->head, last)) == 1)
	{
		//ft_printf("???\n");
		get_next(A->head, pivot)->right = 1;
	}
	else
	{
		//ft_printf("REDO2 %d\n", pivot->x);
		sort(A, B, get_next(A->head, pivot), last);
	} */
}

void	choose_alg(t_stack **A, t_stack **B)
{
/* 	if (is_order(A))
		return ; */
	if (ft_lstsize(*A) == 5)
		order_five(A, B);
	else if (ft_lstsize(*A) == 4)
		order_four(A, B);
	else if (ft_lstsize(*A) == 3)
		order_trio(A);
	else
		sort(A, B);
}

int	main(int argc, char *argv[])
{
	t_ez_stack A;
	t_stack *B;

	if (argc < 2)
		return (0);
	A.head = manage_input(argv);
	A.start = get_smaller(A.head);
	B = 0;	
	choose_alg(&A.head, &B);
	put_first(&A.head, A.start, 1, 1);
	//print_stack(A.head);
	return (0);
}
