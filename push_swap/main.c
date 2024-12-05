/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/05 09:19:22 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_perror(char *msg)
{
	if (msg)
		write(STDERR, msg, ft_strlen(msg));
	return (1);
}

void	sa(t_stack *a)
{
	ft_stack_swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	ft_stack_swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);	
	ft_printf("ss\n");
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

void	ra(t_stack *a)
{
	ft_stack_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	ft_stack_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
	ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	ft_stack_rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	ft_stack_rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_stack_rrotate(a);
	ft_stack_rrotate(b);
	ft_printf("rrr\n");
}

#define TOP 2
#define MID 1
#define BOT 0

void	sort_tiny_stack(t_stack *a)
{
	int	*arr;

	arr = a->values;
	if (a->top < 1)
		return ;
	if (a->top < 2)
	{
		if (arr[BOT] < arr[TOP])
			sa(a);
		return ;
	}
	if (arr[MID] < arr[BOT] && arr[MID] < arr[TOP] && arr[TOP] < arr[BOT])
		return (sa(a));
	if (arr[MID] < arr[BOT] && arr[MID] < arr[TOP] && arr[BOT] < arr[TOP])
		return (ra(a));
	if (arr[MID] > arr[BOT] && arr[MID] < arr[TOP] && arr[BOT] < arr[TOP])
		return (sa(a), rra(a));
	if (arr[MID] > arr[BOT] && arr[MID] > arr[TOP] && arr[BOT] > arr[TOP])
		return (sa(a), ra(a));
	if (arr[MID] > arr[BOT] && arr[MID] > arr[TOP] && arr[BOT] < arr[TOP])
		return (rra(a));

}

int	ft_stack_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->values[i] < s->values[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	push_swap_small(t_stack *a, t_stack *b)
{
	int i;
	
	while (a->top > 2 && !ft_stack_sorted(a))
		pb(a, b);
	sort_tiny_stack(a);
	while (b->top >= 0)
	{
		i = a->top;
		while (i >= 0)
		{
			if (b->values[b->top] < a->values[i])
				break;
			i--;
		}
		if (i == 0)
			(rra(a), pa(a, b), ra(a), ra(a));
		else if (i == a->top)
			(pa(a, b));
		else if (i == a->top - 1)
			(pa(a, b), sa(a));
		else if (i == a->top - 2)
		{
			if (a->top > 2)
				(ra(a), pa(a, b), sa(a), rra(a));
			else
				(rra(a), pa(a, b), ra(a), ra(a));
		}
		else if (i == -1)
			(pa(a, b), ra(a));
	}
}

int	min(int a, int b)
{
	return (a < b);
}

int max(int a, int b)
{
	return (a > b);
}

int	ft_get_index(t_stack *s, int (*cmp)(int, int))
{
	int	out_index;
	int	i;

	out_index = s->top;
	i = 0;
	while (i < s->top)
	{
		if (cmp(s->values[i], s->values[out_index]))
			out_index = i;
		i++;
	}
	return (out_index);
}

void	ft_move_min_to_top(t_stack *a)
{
	int	min_index;

	min_index = ft_get_index(a, min);
	while (min_index != a->top)
	{
		if (min_index < a->top / 2)
		{
			rra(a);
			min_index--;
			if (min_index < 0)
				min_index = a->top;
		}
		else
		{
			ra(a);
			min_index++;
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_print_array(int *arr, int size)
{
	ft_printf("index: [ ");
	for(int i = size - 1; i >= 0; i--)
		ft_printf("%d ", arr[i]);
	ft_printf("]\n");
}

void get_sorted_array_index(t_stack *a)
{
	int	*index;
	int	swap;
	int	i;
	int	j;

	index = malloc((a->top + 1) * sizeof(int));
	i = 0;
	while (i < a->top + 1)
	{
		index[i] = i;
		i++;
	}
	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < a->top)
		{
			if (a->values[index[i]] > a->values[index[i + 1]])
			{
				ft_swap(index + i, index + i + 1);
				swap++;
			}
			i++;
		}
	}
	i = a->top;
	while (i >= 0)
	{
		j = a->top;
		while (j >= 0)
		{
			if (i == index[j])
				a->values[i] = j;
			j--;
		}
		i--;
	}
	free(index);
}

void	push_a_to_b(t_stack *a, t_stack *b)
{
	int middle;

	get_sorted_array_index(a);
	middle = (a->top + 1) / 2;
	while (a->top > 2)
	{
		if (a->values[a->top] > middle)
		{
			pb(a, b);
			rb(b);
		}
		else if (a->values[a->top] < middle)
			pb(a, b);
		else
			ra(a);
	}
}

int	get_pos_in_a(t_stack *a, int value)
{
	int i;
	int j;
	int	min_index;
	int max_index;

	min_index = ft_get_index(a, min);
	max_index = ft_get_index(a, max);
	i = min_index;
	while (i != max_index)
	{
		j = i - 1;
		if (j < 0)
			j = a->top;
		if (a->values[i] < value && value < a->values[j])
			break ;
		i = (i - 1) * (i - 1 >= 0) + a->top * (i - 1 < 0);
	}
	return (i);
}

int	get_cost_of_pos(t_stack *a, t_stack *b, int pos, int i)
{
	int cost_a;
	int cost_b;

	cost_a = ((a->top + 1) - pos) * (pos >= (a->top + 1) / 2) + pos * (pos < (a->top + 1) / 2);
	cost_b = (b->top - i) * (i >= b->top / 2) + (i + 1) * (i < b->top / 2);
	return (cost_a + cost_b + 1);
}

void	push_swap_cost(t_stack *a, t_stack *b)
{
	int pos;
	int	cost;
	int min_cost_pos;
	int	min_cost;
	int	min_cost_index;
	int	i;
	char next[5];

	push_a_to_b(a, b);
	sort_tiny_stack(a);
	while (b->top >= 0)
	{
		i = b->top;
		min_cost_index = i;
		min_cost_pos = get_pos_in_a(a, b->values[i]);
		min_cost = get_cost_of_pos(a, b, pos, i);
		while (i >= 0)
		{
			pos = get_pos_in_a(a, b->values[i]);
			cost = get_cost_of_pos(a, b, pos, i);
			if (cost < min_cost)
			{
				min_cost = cost;
				min_cost_index = i;
				min_cost_pos = pos;
			}
			i--;
		}
		//ft_printf(" min_cost: %d, min_cost_index: %d, min_cost_pos: %d\n", min_cost, min_cost_index, min_cost_pos);
		pos = min_cost_pos;
		// make the min_cost posistion the top of a
		if (pos > (a->top + 1) / 2)
		{
			i = a->top - pos;
			while (i >= 0)
			{
				ra(a);
				i--;
			}
		}
		else
		{
			i = pos;
			while (i > 0)
			{
				rra(a);
				i--;
			}
		}
		// move the min_cost to top in b
		if (min_cost_index > (b->top / 2))
		{
			i = b->top - min_cost_index;
			while (i > 0)
			{
				rb(b);
				i--;
			}
		}
		else
		{
			i = min_cost_index;
			while (i >= 0)
			{
				rrb(b);
				i--;
			}
		}
		pa(a, b);	
		//ft_stack_print(a, 'a');
		//ft_stack_print(b, 'b');
		//scanf("%3s", next);
	}
	int rev = (a->values[a->top] > a->values[a->top / 2]);
    while (a->values[a->top] > a->values[0])
	{
		if (rev)
			ra(a);
		else
			rra(a);
    }
}

void	push_swap_naive(t_stack *a, t_stack *b)
{
	while (a->top > 4  && !ft_stack_sorted(a))
	{
		ft_move_min_to_top(a);
		pb(a, b);
	}
	push_swap_small(a, b);
	while (b->top >= 0)
		pa(a,b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (ft_stack_sorted(a))
		return ;
	if (a->top < 5)
		return push_swap_small(a, b);
	else
		return push_swap_cost(a, b);
}

void	push_swap_console(t_stack *a, t_stack *b)
{
	char buff[10];
	int	count;
	
	count = 0;
	while (1)
	{
		ft_stack_print(a, 'a');
		ft_stack_print(b, 'b');
		scanf("%10s", buff);
		if (strcmp(buff, "sa") == 0)
			sa(a);
		if (strcmp(buff, "sb") == 0)
			sb(b);
		if (strcmp(buff, "pa") == 0)
			pa(a, b);
		if (strcmp(buff, "pb") == 0)
			pb(a, b);
		if (strcmp(buff, "ra") == 0)
			ra(a);
		if (strcmp(buff, "rb") == 0)
			rb(b);
		if (strcmp(buff, "rra") == 0)
			rra(a);
		if (strcmp(buff, "rrb") == 0)
			rrb(b);
		if (strcmp(buff, "index") == 0)
			get_sorted_array_index(a);
		if (strcmp(buff, "test") == 0)
			//ft_printf("min_index: %d, max_index: %d\n",ft_get_index(a, min), ft_get_index(a, max));
			push_swap_cost(a, b);
		count++;
	}
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
		return (ft_perror("Error\n"), 1);
	size = ft_split_count(av);
	a = ft_parse_args(size, av);
	ft_split_free(av);
	if (!a)
		return (ft_perror("Error\n"));
	b = ft_stack_init(size);
	if (!b)
		return (ft_stack_free(a), 1);
	//push_swap_console(a, b);
	push_swap(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
