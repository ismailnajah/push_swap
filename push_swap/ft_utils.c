/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:11 by inajah            #+#    #+#             */
/*   Updated: 2024/12/06 16:03:02 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_seq_len(int *seq, int size)
{
	int i;

	i = 0;
	while (i < size && seq[i] != 0)
		i++;
	return (i);
}

int	*get_biggest_seq(int **seq, int size)
{
	int	biggest_index;
	int biggest_len;
	int i;
	int len;

	biggest_index = 0;
	biggest_len = get_seq_len(seq[0], size);
	i = 1;
	while (i < size)
	{
		len = get_seq_len(seq[i], size);
		if (biggest_len < len)
		{
			biggest_index = i;
			biggest_len = len;
		}
		i++;
	}
	return (seq[biggest_index]);
}

int *get_seq(int *arr, int size, int start)
{
	int i;
	int j;
	int	*seq;

	seq = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
		seq[i++] = -1;
	j = 0;
	seq[0] = arr[start];
	i = start + 1;
	while (i < size + start)
	{
		if (seq[j] > arr[i])
		{
			j++;
			seq[j] = arr[i];
		}
		i++;
	}
	return (seq);
}

int	*get_lds(t_stack *a)
{
	int i;
	int **seq;
	int	*cycle_array;

	seq = malloc((a->top + 1) * sizeof(int *));
	cycle_array = malloc((a->top + 1) * 2 * sizeof(int));
	i = 0;
	while (i < a->top + 1)
	{
		cycle_array[i] = a->values[i];
		cycle_array[i + a->top + 1] = a->values[i];
		i++;
	}
	ft_printf("cycle_array [ ");
	for(int k=0; k < (a->top + 1) * 2; k++)
		ft_printf("%d ", cycle_array[k]);
	ft_printf("]\n");
	i = 0;
	while (i < a->top + 1)
	{
		seq[i] = get_seq(cycle_array, a->top + 1, i);
		i++;
	}
	free(cycle_array);
	return (get_biggest_seq(seq, a->top + 1));
}
