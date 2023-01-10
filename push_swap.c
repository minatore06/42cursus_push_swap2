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
	t_stack *A;
	t_stack *B;
	t_stack *out;

	if (argc < 2)
		return (0);
	A = manage_input(argv);
	B = 0;

	out = A;
	while (out)
	{
		ft_printf("A: %d\n", out->x);
		out = out->next;
	}
	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	pb(&A, &B);
	pb(&A, &B);
	pb(&A, &B);
	pa(&A, &B);
	out = A;
	while (out)
	{
		ft_printf("A: %d\n", out->x);
		out = out->next;
	}
	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	ss(&A, &B);
	out = A;
	while (out)
	{
		ft_printf("A: %d\n", out->x);
		out = out->next;
	}
	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	rr(&A, &B);
	out = A;
	while (out)
	{
		ft_printf("A: %d\n", out->x);
		out = out->next;
	}
	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	rrr(&A, &B);
	out = A;
	while (out)
	{
		ft_printf("A: %d\n", out->x);
		out = out->next;
	}
	out = B;
	while (out)
	{
		ft_printf("B: %d\n", out->x);
		out = out->next;
	}
	return (0);
}
