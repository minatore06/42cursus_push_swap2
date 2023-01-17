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

void	move_to_b(t_stack **A, t_stack **B, t_stack *el)
{
	int	x;
	put_first(A, el);
	pb(A, B);
	return (x);
}

void	swap2el(t_ez_stack A, t_stack **B, t_stack *el1, t_stack *el2)
{
	int	pos1;
	int	pos2;
	int	dis;

	pos1 = lstposition(A.head, el1);
	pos2 = lstposition(A.head, el2);
	move_to_b(A.head, B, el1);
	move_to_b(A.head, B, el2);
	sb(B, 1);
	pa(A.head, B);
	if (ft_lstsize(A.head) - pos2 + pos1)
	while (pos2 - pos1)
	{
		ra(A.head, 1);
		pos2--;
	}
	pa(A.head, B);
}

int	main(int argc, char *argv[])
{
	t_ez_stack A;
	t_stack *B;
	t_stack *pivot;

	if (argc < 2)
		return (0);
	A.head = manage_input(argv);
	A.start = A.head;
	B = 0;
	pivot = get_pivot(A.start);
	move_to_b(&A.head, &B, pivot);
	return (0);
}
