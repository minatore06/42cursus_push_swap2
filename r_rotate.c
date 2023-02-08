/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:37:02 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:37:14 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack *bfrthis(t_stack *lst, t_stack *this)
{
	if (!lst)
		return (lst);
/* 	if (this == lst)
		return (ft_lstlast(lst)); */
	while (lst->next)
	{
		if (lst->next == this)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void rra(t_stack **a, int verbose)
{
	t_stack	*tmp;

	tmp = lstlast(*a);
	tmp->next = *a;
	*a = tmp;
	bfrthis(*a, tmp)->next = 0;
	if (verbose)
		write(1, "rra\n", 4);
}

void rrb(t_stack **b, int verbose)
{
	t_stack	*tmp;

	tmp = lstlast(*b);
	tmp->next = *b;
	*b = tmp;
	bfrthis(*b, tmp)->next = 0;
	if (verbose)
		write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
