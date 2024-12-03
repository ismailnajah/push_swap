/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/03 14:06:13 by inajah           ###   ########.fr       */
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

void	push_swap_small(t_stack *a, t_stack *b)
{
	int i;
	while (a->top > 2)
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

int	ft_get_min_index(t_stack *s)
{
	int	min_index;
	int	i;

	min_index = s->top;
	i = 0;
	while (i < s->top)
	{
		if (s->values[i] < s->values[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	ft_move_min_to_top(t_stack *a)
{
	int	min_index;

	min_index = ft_get_min_index(a);
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

void	ft_push_swap_naive(t_stack *a, t_stack *b)
{
	//ft_stack_print(a, 'a');
	while (a->top > 1 && !ft_stack_sorted(a))
	{
		ft_move_min_to_top(a);
		pb(a, b);
	}
	if (a->values[0] < a->values[1])
		sa(a);
	//ft_printf("-----------------------------------\n");
	//ft_stack_print(a, 'a');
	//ft_stack_print(b, 'b');
	while (b->top >= 0)
		pa(a,b);
	//ft_printf("-----------------------------------\n");
	//ft_stack_print(a, 'a');
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	//return ft_push_swap_naive(a, b);
	while (a->values[0] <= a->values[a->top])
		rra(a);
	ft_stack_print(a, 'a');
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
		if (strcmp(buff, "run") == 0)
			ft_printf("number of runs: %d\n", ft_count_runs(a->values, a->top + 1));
		if (strcmp(buff, "nb") == 0)
			ft_printf("number of instructions: %d\n", count);
		if (strcmp(buff, "test") == 0)
			push_swap_small(a, b);
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
	push_swap_small(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
