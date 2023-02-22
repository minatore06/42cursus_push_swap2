/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:33:43 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/20 16:33:46 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	err_manager(int err)
{
	if (err)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_err(char *argv, int j, t_stack *input)
{
	t_stack	*el;
	long	n;

	if (j != ft_strlen(argv))
		return (err_manager(1));
	n = ft_int_atoi(argv);
	if (n == 3000000000)
		return (err_manager(2));
	el = input;
	while (el)
	{
		if (el->x == n)
			return (err_manager(3));
		el = el->next;
	}
}

t_stack	*manage_input(char **argv)
{
	t_stack	*input;
	int		i;
	int		j;

	input = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				break ;
			j++;
		}
		if (check_err(argv[i], j, input))
			return (NULL);
		ft_lstadd_back(&input, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (input);
}
