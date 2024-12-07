/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:30:00 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 12:56:33 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_insts(t_insts *insts)
{
	insts->pa = 0;
	insts->pb = 0;
	insts->sa = 0;
	insts->sb = 0;
	insts->ss = 0;
	insts->ra = 0;
	insts->rb = 0;
	insts->rra = 0;
	insts->rrb = 0;
	insts->rr = 0;
	insts->rrr = 0;
}

static t_insts	get_same_dir_insts(t_moves a, t_moves b)
{
	t_insts	insts;

	reset_insts(&insts);
	if (ft_max(a.r, b.r) < ft_max(a.rr, b.rr))
	{
		insts.rr = ft_min(a.r, b.r);
		if (a.r < b.r)
			insts.rb = b.r - a.r;
		else
			insts.ra = a.r - b.r;
	}
	else
	{
		insts.rrr = ft_min(a.rr, b.rr);
		if (a.rr < b.rr)
			insts.rrb = b.rr - a.rr;
		else
			insts.rra = a.rr - b.rr;
	}
	return (insts);
}

static t_insts	get_diff_dir_insts(t_moves a, t_moves b)
{
	t_insts	insts;

	reset_insts(&insts);
	if (a.r < a.rr)
		insts.ra = a.r;
	else
		insts.rra = a.rr;
	if (b.r < b.rr)
		insts.rb = b.r;
	else
		insts.rrb = b.rr;
	return (insts);
}

t_insts	get_best_insts(t_stack *a, t_stack *b, t_pos pos, int i)
{
	t_insts	same_dir;
	t_insts	diff_dir;
	t_moves	a_moves;
	t_moves	b_moves;

	a_moves = get_moves_in_a(a, pos);
	b_moves = get_moves_in_b(b, i);
	same_dir = get_same_dir_insts(a_moves, b_moves);
	diff_dir = get_diff_dir_insts(a_moves, b_moves);
	same_dir.cost = same_dir.ra + same_dir.rra + same_dir.rb
		+ same_dir.rrb + same_dir.rr + same_dir.rrr;
	diff_dir.cost = diff_dir.ra + diff_dir.rra + diff_dir.rb
		+ diff_dir.rrb + diff_dir.rr + diff_dir.rrr;
	if (same_dir.cost < diff_dir.cost)
		return (same_dir);
	return (diff_dir);
}

void	execute_insts(t_stack *a, t_stack *b, t_insts insts)
{
	rr(a, b, insts.rr);
	rrr(a, b, insts.rrr);
	ss(a, b, insts.ss);
	ss(a, NULL, insts.sa);
	ss(NULL, b, insts.sb);
	rr(a, NULL, insts.ra);
	rrr(a, NULL, insts.rra);
	rr(NULL, b, insts.rb);
	rrr(NULL, b, insts.rrb);
	if (insts.pa == 1)
		pa(a, b);
	if (insts.pb == 1)
		pb(a, b);
}
