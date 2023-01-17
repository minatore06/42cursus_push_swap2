/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:02:32 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/13 17:03:07 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int lstposition(t_stack *head, t_stack *el)
{
    int x;

    x = 0;
    while (head != el)
    {
        ft_printf("%p ~ %p\n", head, el);
        head = head->next;
        x++;
    }
    return (x);
}
//1 up -1 down
int to_get_first(t_stack *head, t_stack *el)
{
    int x;

    x = lstposition(head, el) + 1;
    if (x <= ft_lstsize(head) / 2 + 1)
        return (1);
    return (-1);
}

void    put_first(t_stack **stack, t_stack *el)
{
    int x;

    x = lstposition(*stack, el);
    if (to_get_first(*stack, el) > 0)
    {
        while (x--)
            ra(stack);
    }
    else
        while (x++ < ft_lstsize(*stack))
            rra(stack);
    return (x);
}