/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:44:04 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/12 13:44:16 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack    *get_pivot(t_stack *lst, t_stack *first, t_stack *last)
{
    t_stack *pivot;
    int     i;
//calcolare la size  tra first e last anche se last si trova prima di first
    i = (ft_lstsize(first) - ft_lstsize(last) + 1) / 2;
    pivot = first;
    while (i > 0)
    {
        if (pivot->next)
            pivot = pivot->next;
        else
            pivot = lst;
        i--;
    }
    ft_printf("str: %d pvt: %d lst: %d\n", first->x, pivot->x, last->x);
    if (pivot->x > first->x)
    {
        if (pivot->x < last->x)
            return (pivot);
        else if (first->x < last->x)
            return (last);
        else
            return (first);
    }
    else if (pivot->x > last->x)
            return (pivot);
    else if (first->x > last->x)
        return (last);
    else
        return (first);
}