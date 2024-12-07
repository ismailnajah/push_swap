/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:11:02 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 11:33:29 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny_stack(t_stack *a)
{
	int	*arr;

	arr = a->values;
	if (a->top < 1)
		return ;
	if (a->top < 2)
	{
		if (arr[0] < arr[1])
			ss(a, NULL, 1);
		return ;
	}
	if (arr[MID] < arr[BOT] && arr[MID] < arr[TOP] && arr[TOP] < arr[BOT])
		return (ss(a, NULL, 1));
	if (arr[MID] < arr[BOT] && arr[MID] < arr[TOP] && arr[BOT] < arr[TOP])
		return (rr(a, NULL, 1));
	if (arr[MID] > arr[BOT] && arr[MID] < arr[TOP] && arr[BOT] < arr[TOP])
		return (ss(a, NULL, 1), rrr(a, NULL, 1));
	if (arr[MID] > arr[BOT] && arr[MID] > arr[TOP] && arr[BOT] > arr[TOP])
		return (ss(a, NULL, 1), rr(a, NULL, 1));
	if (arr[MID] > arr[BOT] && arr[MID] > arr[TOP] && arr[BOT] < arr[TOP])
		return (rrr(a, NULL, 1));
}

void	push_swap_small_helper(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
		(rrr(a, NULL, 1), pa(a, b), rr(a, NULL, 1), rr(a, NULL, 1));
	else if (i == a->top)
		(pa(a, b));
	else if (i == a->top - 1)
		(pa(a, b), ss(a, NULL, 1));
	else if (i == a->top - 2)
	{
		if (a->top > 2)
			(rr(a, NULL, 1), pa(a, b), ss(a, NULL, 1), rrr(a, NULL, 1));
		else
			(rrr(a, NULL, 1), pa(a, b), rr(a, NULL, 1), rr(a, NULL, 1));
	}
	else if (i == -1)
		(pa(a, b), rr(a, NULL, 1));
}

void	push_swap_small(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	j = 0;
	while (a->top > 2 && !ft_stack_sorted(a))
	{
		pb(a, b);
		j++;
	}
	sort_tiny_stack(a);
	while (j > 0)
	{
		i = a->top;
		while (i >= 0)
		{
			if (b->values[b->top] < a->values[i])
				break ;
			i--;
		}
		push_swap_small_helper(a, b, i);
		j--;
	}
}
