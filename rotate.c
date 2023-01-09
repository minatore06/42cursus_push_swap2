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

void ra(t_stack *a)
{
	t_stack	*tmp;

	tmp = lstlast(a);
	tmp->next = a;
	tmp = a->next;
	a->next = 0;
	a = tmp;
}

void rb(t_stack *b)
{
	t_stack	*tmp;

	tmp = lstlast(b);
	tmp->next = b;
	tmp = b->next;
	b->next = 0;
	b = tmp;
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
