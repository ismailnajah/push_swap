/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 11:52:14 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *a)
{
	int	min_index;

	min_index = ft_get_index(a, MIN_INDEX);
	if (min_index > a->top / 2)
		rr(a, NULL, a->top - min_index);
	else
		rrr(a, NULL, min_index + 1);
}

void	push_swap_cost(t_stack *a, t_stack *b)
{
	t_insts	min_insts;
	t_insts	insts;
	t_pos	pos;
	int		i;

	push_a_to_b(a, b);
	if (a->top == 4)
		push_swap_small(a, b);
	while (b->top >= 0)
	{
		i = b->top;
		pos = get_pos_in_a(a, b->values[i]);
		min_insts = get_best_insts(a, b, pos, i);
		while (i >= 0)
		{
			pos = get_pos_in_a(a, b->values[i]);
			insts = get_best_insts(a, b, pos, i);
			if (insts.cost < min_insts.cost)
				min_insts = insts;
			i--;
		}
		execute_insts(a, b, min_insts);
		pa(a, b);
	}
	move_min_to_top(a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (ft_stack_sorted(a))
		return ;
	if (a->top < 5)
		return (push_swap_small(a, b));
	else
		return (push_swap_cost(a, b));
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
		return (ft_perror("Error\n"));
	size = ft_split_count(av);
	a = ft_parse_args(size, av);
	ft_split_free(av);
	if (!a)
		return (ft_perror("Error\n"));
	b = ft_stack_init(size);
	if (!b)
		return (ft_stack_free(a), ft_perror("Error\n"));
	push_swap(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
