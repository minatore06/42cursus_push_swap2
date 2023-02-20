/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:48 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/20 16:10:51 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move_to_b(t_stack **A, t_stack **B, t_stack *el, int verbose)
{
	//if (verbose)
		//ft_printf("Sto spostando in b %d\n", el->x);
	put_first(A, el, verbose, 1);
	//put_first_test(A, B, el);
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
	while(el && !el->right)
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
	while(el && !el->right)
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
