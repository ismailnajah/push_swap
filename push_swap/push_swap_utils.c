/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:05:02 by inajah            #+#    #+#             */
/*   Updated: 2024/12/24 18:28:18 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(t_stack *s, int min_index)
{
	int	out_index;
	int	i;

	out_index = s->top;
	i = 0;
	while (i < s->top)
	{
		if (min_index && s->values[i] < s->values[out_index])
			out_index = i;
		if (!min_index && s->values[i] > s->values[out_index])
			out_index = i;
		i++;
	}
	return (out_index);
}

static void	get_sorted_array_indexes(t_stack *a, int *indexes)
{
	int	swap;
	int	i;

	i = 0;
	while (i < a->top + 1)
	{
		indexes[i] = i;
		i++;
	}
	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < a->top)
		{
			if (a->values[indexes[i]] > a->values[indexes[i + 1]])
				swap += ft_swap(indexes + i, indexes + i + 1);
			i++;
		}
	}
}

static void	map_a_to_final_indexes(t_stack *a, int *indexes)
{
	int	i;
	int	j;

	get_sorted_array_indexes(a, indexes);
	i = a->top;
	while (i >= 0)
	{
		j = a->top;
		while (j >= 0)
		{
			if (i == indexes[j])
				a->values[i] = j;
			j--;
		}
		i--;
	}
}

void	push_a_to_b(t_stack *a, t_stack *b)
{
	int	middle;

	map_a_to_final_indexes(a, b->values);
	middle = (a->top + 1) / 2;
	while (a->top > 4 && !ft_stack_sorted(a))
	{
		if (a->values[a->top] > middle)
		{
			pb(a, b);
			rr(NULL, b, 1);
		}
		else if (a->values[a->top] < middle)
			pb(a, b);
		else
			rr(a, NULL, 1);
	}
}

t_pos	get_pos_in_a(t_stack *a, int value)
{
	t_pos	pos;
	int		min_index;
	int		max_index;

	min_index = ft_get_index(a, MIN_INDEX);
	max_index = ft_get_index(a, MAX_INDEX);
	pos.above = min_index;
	while (pos.above != max_index)
	{
		pos.below = pos.above - 1;
		if (pos.below < 0)
			pos.below = a->top;
		if (a->values[pos.above] < value && value < a->values[pos.below])
			break ;
		if (pos.above - 1 >= 0)
			pos.above -= 1;
		else
			pos.above = a->top;
	}
	if (pos.above == max_index)
		pos.below = pos.above - 1;
	if (pos.below < 0)
		pos.below = a->top;
	return (pos);
}
