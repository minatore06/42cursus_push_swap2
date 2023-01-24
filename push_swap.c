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
	move_to_b(A, B, el1);
	go_first = *A;
	move_to_b(A, B, el2);
	print_stack(*A);
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
		ft_printf("%d\n", A->x);
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
	while (size > 0)
	{
		small = A;
		i = 0;
		while (i++ < size)
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

void	sort(t_stack **A, t_stack **B, t_stack *start)
{
	t_stack *pivot;
	t_stack	*left_big;
	t_stack	*right_small;

	pivot = get_pivot(*A);
	ft_printf("size: %d, el: %d\n",ft_lstsize(*A), pivot->x);
	move_to_b(A, &B, pivot);
	put_first(A, start);
	swap2el(A, B, get_first_bigger(*A, pivot->x), get_last_smaller(*A, pivot->x));
	
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
	sort(&A.head, &B, A.start);
	print_stack(A.head);
	return (0);
}
