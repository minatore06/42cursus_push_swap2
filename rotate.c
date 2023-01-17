/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:27:34 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:27:46 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack *lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ra(t_stack **a, int verbose)
{
	t_stack	*tmp;

	tmp = lstlast(*a);
	tmp->next = *a;
	tmp = (*a)->next;
	(*a)->next = 0;
	*a = tmp;
	if (verbose)
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int verbose)
{
	t_stack	*tmp;

	tmp = lstlast(*b);
	tmp->next = *b;
	tmp = (*b)->next;
	(*b)->next = 0;
	*b = tmp;
	if (verbose)
		write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
