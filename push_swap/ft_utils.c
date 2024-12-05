/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:11 by inajah            #+#    #+#             */
/*   Updated: 2024/12/05 16:22:06 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_realloc(int *arr, int size)
{
	int *out;
	int i;

	out = malloc(size * sizeof(int));
	i = 0;
	while (i < size - 1)
	{
		seq
	}
}

int *get_seq(t_stack *a, int start)
{
	int i;
	int j;
	int	*seq;

	j = 0;
	seq = malloc(sizeof(int));
	seq[0] = a->values[start];
	start = (start - 1) * (start - 1 >= 0) + a->top * (start - 1 < 0);
	i = 0;
	while (i <= a->top)
	{
		if (seq[j] < a->values[start])
		{
			j++;
			seq = ft_realloc(seq, j + 1);
			seq[j] = a->values[start]
		}
		start = (start - 1) * (start - 1 >= 0) + a->top * (start - 1 < 0);
		i++;
	}
}

int	*get_lds(t_stack *a)
{
	int **seq;
	int	start;

	seq = malloc((a->top + 1) * sizeof(int *));
	while (i < a->top)
	{
		start = i;
		seq[i] = get_seq(t_stack, start);
		i--;
	}
}
