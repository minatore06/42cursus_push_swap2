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

void	move_to_b(t_stack **a, t_stack **b, t_stack *el, int verbose)
{
	put_first(a, el, verbose, 1);
	pb(a, b, verbose);
}

void	move_to_a(t_stack **a, t_stack **b, t_stack *el, int verbose)
{
	put_first(b, el, verbose, 0);
	pa(a, b, verbose);
}

void	move_smallers(t_stack **a, t_stack **b, t_stack *pivot, int direction)
{
	t_stack	*el;

	el = *a;
	while (el && !el->right)
	{
		if (el->x < pivot->x)
		{
			if (direction == 1)
				move_to_a(a, b, el, 1);
			else if (direction == -1)
				move_to_b(a, b, el, 1);
			el = *a;
			continue ;
		}
		el = el->next;
	}
	if (direction == 1)
		move_to_a(a, b, pivot, 1);
	else if (direction == -1)
		move_to_b(a, b, pivot, 1);
}

void	move_largers(t_stack **a, t_stack **b, t_stack *pivot, int direction)
{
	t_stack	*el;

	el = *b;
	while (el && !el->right)
	{
		if (el->x > pivot->x)
		{
			if (direction == 1)
				move_to_a(a, b, el, 1);
			else if (direction == -1)
				move_to_b(a, b, el, 1);
			el = *b;
			continue ;
		}
		el = el->next;
	}
	if (direction == 1)
		move_to_a(a, b, pivot, 1);
	else if (direction == -1)
		move_to_b(a, b, pivot, 1);
	pivot->right = 1;
}
