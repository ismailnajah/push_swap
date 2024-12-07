/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_insts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:40:17 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 12:50:10 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_swap(a);
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_swap(b);
		iter--;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	ft_stack_push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_stack_push(b, a);
}

void	rr(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_rotate(a);
		ft_stack_rotate(b);
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_rotate(a);
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_rotate(b);
		iter--;
	}
}

void	rrr(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_rrotate(a);
		ft_stack_rrotate(b);
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_rrotate(a);
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_rrotate(b);
		iter--;
	}
}
