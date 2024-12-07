/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:32:23 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 10:39:37 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	lowest_moves(t_moves a, t_moves b)
{
	if (a.cost < b.cost)
		return (a);
	return (b);
}

t_moves	get_moves_in_a(t_stack *a, t_pos pos)
{
	t_moves	above_moves;
	t_moves	below_moves;

	above_moves.r = a->top - pos.above + 1;
	above_moves.rr = pos.above;
	above_moves.cost = ft_min(above_moves.r, above_moves.rr);
	below_moves.r = a->top - pos.below;
	below_moves.rr = pos.below + 1;
	below_moves.cost = ft_min(below_moves.r, below_moves.rr);
	return (lowest_moves(above_moves, below_moves));
}

t_moves	get_moves_in_b(t_stack *b, int i)
{
	t_moves	moves;

	moves.r = b->top - i;
	moves.rr = i + 1;
	moves.cost = ft_min(moves.r, moves.rr);
	return (moves);
}
