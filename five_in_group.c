/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_in_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:34:28 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/24 15:34:30 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_two_sm_qt(t_stack **a, t_stack *start, t_stack **sm1, t_stack **sm2)
{
	t_stack	*b2;

	b2 = 0;
	pb(a, &b2, 0);
	pb(a, &b2, 0);
	pb(a, &b2, 0);
	pb(a, &b2, 0);
	pb(a, &b2, 0);
	*sm1 = get_smaller(b2);
	move_to_a(a, &b2, *sm1, 0);
	*sm2 = get_smaller(b2);
	move_to_b(a, &b2, *sm1, 0);
	put_first(&b2, get_next(b2, start), 0, 0);
	pa(a, &b2, 0);
	pa(a, &b2, 0);
	pa(a, &b2, 0);
	pa(a, &b2, 0);
	pa(a, &b2, 0);
}

void	five_in_group(t_stack **a, t_stack **b, t_stack *five)
{
	t_stack	*smaller1;
	t_stack	*smaller2;

	put_first(a, five, 1, 1);
	get_two_sm_qt(a, five, &smaller1, &smaller2);
	while (five == smaller1 || five == smaller2)
		five = five->next;
	move_to_b(a, b, smaller1, 1);
	move_to_b(a, b, smaller2, 1);
	five = trio_in_group(a, five);
	put_first(a, five, 1, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	smaller1->right = 1;
	smaller2->right = 1;
}
