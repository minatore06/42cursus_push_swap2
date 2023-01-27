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

void	print_stack(t_stack *s)
{
	while (s)
	{
		ft_printf("A: %d | ", s->x);
		s = s->next;
	}
	ft_printf("\n");
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

void	move_to_b(t_stack **A, t_stack **B, t_stack *el)
{
	put_first(A, el);
	pb(A, B);
}

void	swap2el(t_stack **A, t_stack **B, t_stack *el1, t_stack *el2)
{
	t_stack	*go_first;

	if (el1->next == el2)
	{
		put_first(A, el1);
		sa(A, 1);
		return;
	}
	go_first = el1->next;
	move_to_b(A, B, el1);
	move_to_b(A, B, el2);
	//print_stack(*A);
	sb(B, 1);
	pa(A, B);
	put_first(A, go_first);
	pa(A, B);
	//print_stack(A.head);
}

void	swap_pivot(t_stack **A, t_stack **B, t_stack *last, t_stack *el2)
{
	t_stack	*go_first;

	go_first = last->next;
	if (go_first == el2)
		go_first = el2->next;
	if (!go_first)
	{
		//ft_printf("sos\n");
		go_first = *A;
	}
	move_to_b(A, B, el2);
	//print_stack(*A);
	sb(B, 1);
	pa(A, B);
	put_first(A, go_first);
	pa(A, B);
	//print_stack(A.head);
}

t_stack	*get_first_bigger(t_stack *A, int pivot)
{
	int		size;

	size = ft_lstsize(A);
	while (size--)
	{
		//ft_printf("%d\n", A->x);
		if (A->x > pivot && !A->right)
			return (A);
		A = A->next;
	}
	return (0);
}

t_stack	*get_last_smaller(t_stack *A, int pivot)
{
	t_stack	*small;
	int		size;
	int		i;

	size = ft_lstsize(A) - 1;
	while (size >= 0)
	{
		small = A;
		i = 0;
		while (size - i++)
			small = small->next;
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

int	left_is_right(t_stack *big, t_stack *small)
{
		//ft_printf("small: %p, big: %p\n", small, big);
	while (small)
	{
		if (small == big)
			return (1);
		small = small->next;
	}
	return (0);
}

int	is_order(t_stack *start, t_stack *end)
{
	int	old;

	old = start->x;
	start = start->next;
	while (start != end)
	{
		if (old > start->x)
			return (0);
		old = start->x;
		start = start->next;
	}
	return (1);
}

void	sort(t_ez_stack *A, t_stack **B, t_stack *first, t_stack *last)
{
	t_stack *pivot;
	t_stack	*big_left;
	t_stack	*small_right;

	if (is_order(first, last))
		return ;
	pivot = get_pivot(first, bfrthis(A->head, last));
	//ft_printf("size: %d, str: %d pvt: %d lst: %d\n",ft_lstsize(A->head), first->x, pivot->x, bfrthis(A->head, last)->x);
	move_to_b(&A->head, B, pivot);
	while (1)
	{
		put_first(&A->head, A->start);
		big_left = get_first_bigger(A->head, pivot->x);
		small_right = get_last_smaller(A->head, pivot->x);
		if (left_is_right(big_left, small_right))
			break;
		else
			swap2el(&A->head, B, big_left, small_right);
	}
	//ft_printf("MEGA\n");
	swap_pivot(&A->head, B, bfrthis(A->head, last), big_left);
	put_first(&A->head, A->start);
	pivot->right = 1;
	if (lstposition(A->head, pivot) - lstposition(A->head, first) == 2)
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
	else if (lstposition(A->head, pivot) - lstposition(A->head, first) == 1){
		//ft_printf("?\n");
		bfrthis(A->head, pivot)->right = 1;}
	else{
		//ft_printf("REDO1\n");
		sort(A, B, first, bfrthis(A->head, pivot));}
	if (lstposition(A->head, bfrthis(A->head, last)) - lstposition(A->head, pivot) == 2)
	{
		//ft_printf("22\n");
		pivot = pivot->next;
		if (pivot->x > ((t_stack *)pivot->next)->x)
			swap2el(&A->head, B, pivot, pivot->next);
		else
		{
			pivot->right = 1;
			((t_stack *)pivot->next)->right = 1;
		}
	}
	else if (lstposition(A->head, bfrthis(A->head, last)) - lstposition(A->head, pivot) == 1)
	{
		//ft_printf("???\n");
		((t_stack *)pivot->next)->right = 1;
	}
	else
	{
		//ft_printf("REDO2 %d\n", pivot->x);
		sort(A, B, pivot->next, last);
	}
}

int	main(int argc, char *argv[])
{
	t_ez_stack A;
	t_stack *B;

	if (argc < 2)
		return (0);
	A.head = manage_input(argv);
	A.start = get_smaller(A.head);
	put_first(&A.head, A.start);
	B = 0;	
/* 	if (is_order(A))
		return ; */
	sort(&A, &B, A.start, NULL);
	//print_stack(A.head);
	put_first(&A.head, A.start);
	return (0);
}
