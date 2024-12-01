/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:52:36 by inajah            #+#    #+#             */
/*   Updated: 2024/12/01 17:26:04 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->values[s->top];
	s->values[s->top] = s->values[s->top - 1];
	s->values[s->top - 1] = tmp;
}

void	ft_stack_push(t_stack *src, t_stack *dst)
{
	if (src->top < 0)
		return ;
	dst->top++;
	dst->values[dst->top] = src->values[src->top];
	src->top--;
}

void	ft_stack_rotate(t_stack *s)
{
	int i;
	int first;

	i = s->top;
	first = s->values[s->top];
	while (i > 0)
	{
		s->values[i] = s->values[i - 1];
		i--;
	}
	s->values[0] = first;
}

void	ft_stack_rrotate(t_stack *s)
{
	int	i;
	int last;

	i = 0;
	last = s->values[0];
	while (i < s->top)
	{
		s->values[i] = s->values[i + 1];
		i++;
	}
	s->values[s->top] = last;
}
