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

t_stack *manage_input(char **argv)
{
	t_stack	*input;
	int	n;
	int	i;
	int	j;

	input = 0;
	i = 1;
	while (argv[i])
	{
		j= 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				break ;
			j++;
		}
		if (j != ft_strlen(argv[i]))
			return (input);
		n = ft_atoi(argv[i]);
		ft_lstadd_back(&input, ft_lstnew(n));
		i++;
	}
	return (input);
}

int	main(int argc, char *argv[])
{
	t_ez_stack A;
	t_stack *B;
	t_stack *out;

	if (argc < 2)
		return (0);
	A.head = manage_input(argv);
	A.start = A.head;
	B = 0;

	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	ft_printf("Pivot: %d\n", get_pivot(A.start)->x);
	put_first(&A.head, get_pivot(A.start));
	while (A.head)
	{
		ft_printf("A: %d\n", A.head->x);
		A.head = A.head->next;
	}
	return (0);
}
