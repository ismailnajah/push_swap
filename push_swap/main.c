/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/02 09:24:51 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(char *msg)
{
	if (msg)
		write(STDERR, msg, ft_strlen(msg));
	return (1);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{	
	ft_stack_print(a, 'a');
	ft_stack_print(b, 'b');
	ft_printf("---------------\n");

	ft_stack_swap(a);
	ft_stack_push(a, b);
	ft_stack_swap(b);

	ft_stack_print(a, 'a');
	ft_stack_print(b, 'b');
	ft_printf("---------------\n");

	ft_stack_rotate(a);

	ft_stack_print(a, 'a');
	ft_stack_print(b, 'b');
	ft_printf("---------------\n");

	ft_stack_rrotate(a);

	ft_stack_print(a, 'a');
	ft_stack_print(b, 'b');
	ft_printf("---------------\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac == 1)
		return (1);
	av = ft_get_args(ac, av);
	if (!av)
		return (ft_perror("Error\n"), 1);
	size = ft_split_count(av);
	a = ft_parse_args(size, av);
	ft_split_free(av);
	if (!a)
		return (ft_perror("Error\n"));
	b = ft_stack_init(size);
	if (!b)
		return (ft_stack_free(a), 1);
	ft_push_swap(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
