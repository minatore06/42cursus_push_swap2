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

t_stack *manage_input(char **argv)
{
	t_stack	*input;
	t_stack	*el;
	long    n;
	int	    i;
	int	    j;

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
		}// returnare null non va bene, mandare messaggio di errore prima e poi non fare nulla nel main in caso di null
		if (j != ft_strlen(argv[i]))
			return (NULL);
		n = ft_int_atoi(argv[i]);
        if (n == 3000000000)
            return (NULL);
        el = input;
        while (el)
        {
            if (el->x == n)
                return (NULL);
        }
		ft_lstadd_back(&input, ft_lstnew(n));
		i++;
	}
	return (input);
}
