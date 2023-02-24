/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:59 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 14:33:02 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* void	print_stack(t_stack *s)
{
	while (s)
	{
		ft_printf("%d|", s->x);
		if (s->right)
			ft_printf("\\/");
		ft_printf("\n");
		s = s->next;
	}
	ft_printf("a\n");
} */

void	choose_alg(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 5)
		order_five(a, b);
	else if (ft_lstsize(*a) == 4)
		order_four(a, b);
	else if (ft_lstsize(*a) == 3)
		order_trio(a);
	else
		sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_ez_stack	a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a.head = manage_input(argv);
	if (!a.head)
		return (0);
	a.start = get_smaller(a.head);
	b = 0;
	if (!is_order(a.head, a.start))
		choose_alg(&a.head, &b);
	put_first(&a.head, a.start, 1, 1);
	return (0);
}
