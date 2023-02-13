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
		ft_printf("%d|", s->x);
		if (s->right)
			ft_printf("\\/");
		ft_printf("\n");
		s = s->next;
	}
	ft_printf("A\n");
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
	ft_printf("Sto spostando in b %d\n", el->x);
	put_first(A, el, verbose);
	pb(A, B, 1);
}

void	move_to_a(t_stack **A, t_stack **B, t_stack *el, int verbose)
{
	ft_printf("Sto spostando in a %d\n", el->x);
	put_first(B, el, verbose);
	pa(A, B, 1);
}

void	move_smallers(t_stack **A, t_stack **B, t_stack *pivot)
{
	t_stack	*el;

	el = *A;
	while(el)
	{
		if (el->x < pivot->x)
		{
			move_to_b(A, B, el, 1);
			el = *A;
			continue ;
		}
		el = el->next;
	}
	move_to_b(A, B, pivot, 1);
}

void	move_largers(t_stack **A, t_stack **B, t_stack *pivot)
{
	t_stack	*el;

	el = *B;
	while(el)
	{
		if (el->x > pivot->x)
		{
			move_to_a(A, B, el, 1);
			el = *B;
			continue ;
		}
		el = el->next;
	}
	move_to_a(A, B, pivot, 1);
	pivot->right = 1;
}

void	swap2el(t_stack **A, t_stack **B, t_stack *el1, t_stack *el2)
{
	t_stack	*go_first;

	if (get_next(*A, el1) == el2)
	{
		put_first(A, el1, 1);
		sa(A, 1);
		return;
	}
	go_first = get_next(*A, el1);
	move_to_b(A, B, el1, 1);
	move_to_b(A, B, el2, 1);
	//print_stack(*A);
	sb(B, 1);
	pa(A, B, 1);
	put_first(A, go_first, 1);
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
	put_first(A, go_first, 1);
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

void	order_trio(t_stack **lst)
{
	int	big_pos;
	int	small_pos;

	big_pos = lstposition(*lst, get_bigger(*lst));
	small_pos = lstposition(*lst, get_smaller(*lst));
	if (big_pos + small_pos == 1)
	{
		if (big_pos > small_pos)
			sa(lst, 1);
		ra(lst, 1);
	}
	else if (big_pos + small_pos == 2)
	{
		if (big_pos < small_pos)
		{
			sa(lst, 1);
			rra(lst, 1);
		}
	}
	else if (big_pos + small_pos == 3)
	{
		if (big_pos > small_pos)
			sa(lst, 1);
		else
			rra(lst, 1);
	}
}

void	order_four(t_stack **A, t_stack **B)
{
	int	big_weight;
	int	small_weight;

	big_weight = ft_abs(2 - lstposition(*A, get_bigger(*A))) - 1;
	small_weight = ft_abs(2 - lstposition(*A, get_smaller(*A)));
	if (big_weight > small_weight)
		move_to_b(A, B, get_bigger(*A), 1);
	else
		move_to_b(A, B, get_smaller(*A), 1);
	order_trio(A);
	pa(A, B, 1);
	if (big_weight > small_weight)
		ra(A, 1);
}

void	order_five(t_stack **A, t_stack **B)
{
	move_to_b(A, B, get_smaller(*A), 1);
	move_to_b(A, B, get_smaller(*A), 1);
	order_trio(A);
	pa(A, B, 1);
	pa(A, B, 1);
}

int		is_number_between(t_stack *lst, t_stack *small, t_stack *big)
{
	while (lst)
	{
		if (lst == small || lst == big)
		{
			lst = lst->next;
			continue ;
		}
		if (lst->x > small->x && lst->x < big->x)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	alone_numbers(t_stack *alone)
{
	alone->right = 1;
}

void	couple_numbers(t_stack **A, t_stack *couple)
{
	couple->right = 1;
	get_next(*A, couple)->right = 1;
	if (couple->x > get_next(*A, couple)->x)
	{
		put_first(A, couple, 1);
		sa(A, 1);
	}
}

t_stack	*consecutive_numbers(t_stack *A, t_stack *el, int sec)
{
	t_stack	*check;

	check = el;
	while (check->next)
	{
		if (check->x < get_next(A, check)->x && !is_number_between(A, check, get_next(A, check)))
			get_next(A, check)->right = 1;
		else
			break ;
		check = check->next;
	}
	while (bfrthis(A, el))
	{
		if (el->x > bfrthis(A, el)->x && !is_number_between(A, bfrthis(A, el), el))
			bfrthis(A, el)->right = 1;
		else
			break ;
		el = bfrthis(A, el);
	}
	if (sec)
		return (el);
	return (check);
}

void	trio_in_group(t_stack **lst, t_stack *trio)
{
	t_stack	*bigger;
	t_stack	*smaller;
	int		big_pos;
	int		small_pos;

	put_first(lst, trio, 1);
	if (trio->x > get_next(*lst, trio)->x)
	{
		bigger = trio;
		smaller = get_next(*lst, trio);
		if (trio->x > get_next(*lst, get_next(*lst, trio))->x)
		{
			if (get_next(*lst, trio)->x > get_next(*lst, get_next(*lst, trio))->x)
				smaller = get_next(*lst, get_next(*lst, trio));
		}
		else
			bigger = get_next(*lst, get_next(*lst, trio));
	}
	else
	{
		bigger = get_next(*lst, trio);
		smaller = trio;
		if (get_next(*lst, trio)->x > get_next(*lst, get_next(*lst, trio))->x)
		{
			if (trio->x > get_next(*lst, get_next(*lst, trio))->x)
				smaller = get_next(*lst, get_next(*lst, trio));
		}
		else
			bigger = get_next(*lst, get_next(*lst, trio));
	}
	big_pos = lstposition(*lst, bigger);
	small_pos = lstposition(*lst, smaller);
	if (big_pos + small_pos == 1)
	{
		if (big_pos < small_pos)
			sa(lst, 1);
		ra(lst, 1);
		sa(lst, 1);
	}
	else if (big_pos + small_pos == 2)
	{
		if (big_pos < small_pos)
		{
			sa(lst, 1);
			ra(lst, 1);
			sa(lst, 1);
			rra(lst, 1);
			sa(lst, 1);
		}
	}
	else if (big_pos + small_pos == 3)
	{
		if (big_pos < small_pos)
		{
			ra(lst, 1);
			sa(lst, 1);
			rra(lst, 1);
		}
		sa(lst, 1);
	}
	trio->right = 1;
	get_next(*lst, trio)->right = 1;
	get_next(*lst, get_next(*lst, trio))->right = 1;
}

void	four_in_group(t_stack **A, t_stack **B, t_stack *four)
{
	int		big_weight;
	int		small_weight;
	t_stack	*bigger;
	t_stack	*smaller;

	put_first(A, four, 1);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	bigger = get_bigger(*B);
	smaller = get_smaller(*B);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	big_weight = lstposition(*A, bigger) + 3;
	small_weight = lstposition(*A, smaller);
	if (small_weight == 0 || big_weight - 3 == 0)
		four = four->next;
	if (big_weight < small_weight)
		move_to_b(A, B, bigger, 1);
	else
		move_to_b(A, B, smaller, 1);
	trio_in_group(A, four);
	if (big_weight < small_weight)
		put_first(A, get_next(*A, get_next(*A, get_next(*A, four))), 1);
	else
		put_first(A, four, 1);
	pa(A, B, 1);
	smaller->right = 1;
	bigger->right = 1;
}

void	five_in_group(t_stack **A, t_stack **B, t_stack *five)
{
	t_stack	*smaller1;
	t_stack	*smaller2;

	put_first(A, five, 1);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	smaller1 = get_smaller(*B);
	move_to_a(A, B, smaller1, 0);
	smaller2 = get_smaller(*B);
	move_to_b(A, B, smaller1, 0);
	put_first(B, get_next(*B, five), 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	while (five == smaller1 || five == smaller2)
		five = five->next;
	move_to_b(A, B, smaller1, 1);
	move_to_b(A, B, smaller2, 1);
	trio_in_group(A, five);
	put_first(A, five, 1);
	pa(A, B, 1);
	pa(A, B, 1);
	smaller1->right = 1;
	smaller2->right = 1;
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
					ft_printf("first %d, second %d\n", first->x, second->x);
					if (get_distance(*A, first, second) == 1)
						alone_numbers(get_next(*A, first));
					else if (get_distance(*A, first, second) == 2)
						couple_numbers(A, get_next(*A, first));
					else if (get_distance(*A, first, second) == 3)
						trio_in_group(A, get_next(*A, first));
					else if (get_distance(*A, first, second) == 4)
						four_in_group(A, B, get_next(*A, first));
					else if (get_distance(*A, first, second) == 5)
						five_in_group(A, B, get_next(*A, first));
					break ;
				}
				lst = lst->next;
			}
			lst = first;
		}
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
	//ft_printf("bfr last %p\n", last);
	pivot = get_pivot(*A, get_smaller(*A), get_bigger(*A));
	ft_printf("size: %d, pivot %d\n",ft_lstsize(*A), pivot->x);
	move_smallers(A, B, pivot);
	pa(A, B, 1);
	pivot->right = 1;
	while (1)
	{
		print_stack(*A);
		if (ft_lstsize(*B) == 1)
		{
			pa(A, B, 1);
			(*A)->right = 1;
			break;
		}
		else if (ft_lstsize(*B) == 2)
		{
			if ((*B)->x < get_next(*B, *B)->x)
				sb(B, 1);
			pa(A, B, 1);
			(*A)->right = 1;
			pa(A, B, 1);
			(*A)->right = 1;
			break;
		}
		pivot = get_pivot(*B, get_smaller(*B), get_bigger(*B));
		move_largers(A, B, pivot);
	}
	print_stack(*A);
	ft_printf("MEGA\n");
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
	put_first(&A.head, A.start, 1);
	print_stack(A.head);
	return (0);
}
