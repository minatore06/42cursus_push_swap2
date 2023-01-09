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
	while (lst->next != this)
		lst = lst->next;
	return (lst);
}

void rra(t_stack *a)
{
	t_stack	*tmp;

	tmp = lstlast(a);
	tmp->next = a;
	a = tmp;
	bfrthis(a, tmp)->next = 0;
}

void rrb(t_stack *b)
{
	t_stack	*tmp;

	tmp = lstlast(b);
	tmp->next = b;
	b = tmp;
	bfrthis(b, tmp)->next = 0;
}

void rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
