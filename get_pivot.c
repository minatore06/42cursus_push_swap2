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

int first_before_last(t_stack *first, t_stack *last)
{
    while (first)
    {
        if (first == last)                         
            return (1);
        first = first->next;
    }
    return (0);
}

t_stack    *get_pivot(t_stack *lst, t_stack *first, t_stack *last)
{
    t_stack *pivot;
    int     i;

    i = get_distance(lst, first, last) / 2;
    pivot = first;
    while (i > 0)
    {
        pivot = get_next(lst, pivot);
        i--;
    }
    ////ft_printf("str: %d pvt: %d lst: %d\n", first->x, pivot->x, last->x);
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