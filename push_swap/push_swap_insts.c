/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:40:17 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 10:43:33 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
		ft_printf("ss\n");
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_swap(a);
		ft_printf("sa\n");
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_swap(b);
		ft_printf("sb\n");
		iter--;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	ft_stack_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	ft_stack_push(b, a);
	ft_printf("pb\n");
}

void	rr(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_rotate(a);
		ft_stack_rotate(b);
		ft_printf("rr\n");
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_rotate(a);
		ft_printf("ra\n");
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_rotate(b);
		ft_printf("rb\n");
		iter--;
	}
}

void	rrr(t_stack *a, t_stack *b, int iter)
{
	while (a && b && iter > 0)
	{
		ft_stack_rrotate(a);
		ft_stack_rrotate(b);
		ft_printf("rrr\n");
		iter--;
	}
	while (a && iter > 0)
	{
		ft_stack_rrotate(a);
		ft_printf("rra\n");
		iter--;
	}
	while (b && iter > 0)
	{
		ft_stack_rrotate(b);
		ft_printf("rrb\n");
		iter--;
	}
}
