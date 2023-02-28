/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:24:55 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/28 12:24:57 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*get_next(t_stack *a, t_stack *el)
{
	if (el->next)
		return (el->next);
	return (a);
}

int	is_order(t_stack *lst, t_stack *start)
{
	int		old;
	t_stack	*el;

	old = start->x;
	el = get_next(lst, start);
	while (el && el != start)
	{
		if (old > el->x)
			return (0);
		old = el->x;
		el = get_next(lst, el);
	}
	return (1);
}
