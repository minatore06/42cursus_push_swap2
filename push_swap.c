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
/* void	print_stack(t_stack *s)
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
} */

int	ft_abs(int	x)
{
	if (x < 0)
		x = -x;
	return (x);
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
	if (!A.head)
		return (0);
	A.start = get_smaller(A.head);
	B = 0;	
	choose_alg(&A.head, &B);
	put_first(&A.head, A.start, 1, 1);
	//print_stack(A.head);
	return (0);
}
