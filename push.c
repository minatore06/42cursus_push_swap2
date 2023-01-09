/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:53 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:03:54 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b)
		return ;
	tmp = b;
	b = b->next;
	tmp->next = a;
	a = tmp;
}

void pb(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!a)
		return ;
	tmp = a;
	a = a->next;
	tmp->next = b;
	b = tmp;
}
