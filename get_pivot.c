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

t_stack    *get_pivot(t_stack *first, t_stack *last)
{
    t_stack *pivot;
    int     i;

    i = ft_lstsize(first) / 2;
    pivot = first;
    while (i > 0)
    {
        pivot = pivot->next;
        i--;
    }
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