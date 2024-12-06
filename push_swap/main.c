/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/06 20:44:06 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_tiny_stack(t_stack *a);

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

int ft_in_array(int *arr, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	push_a_to_b(t_stack *a, t_stack *b)
{
	int middle;

	get_sorted_array_index(a);
	middle = (a->top + 1) / 2;
	while (a->top > 2 && !ft_stack_sorted(a))
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

//////////////////////////////////////////////////////////////////////////////////////

void	print_insts(t_insts i)
{
	ft_printf(" # [ra: %d, rra: %d, rb: %d, rrb: %d, rr: %d, rrr: %d]\n", i.ra,
			i.rra, i.rb, i.rrb, i.rr, i.rrr);
}

t_pos	_get_pos_in_a(t_stack *a, int value)
{	
	t_pos	pos;
	int	min_index;
	int max_index;

	min_index = ft_get_index(a, min);
	max_index = ft_get_index(a, max);
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

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_moves	lowest_moves(t_moves a, t_moves b)
{
	if (a.cost < b.cost)
		return (a);
	return (b);
}

t_moves	get_moves_in_a(t_stack *a, t_pos pos)
{
	t_moves above_moves;
	t_moves below_moves;
	
	above_moves.r = a->top - pos.above + 1;
	above_moves.rr = pos.above;
	above_moves.cost = ft_min(above_moves.r, above_moves.rr);
	below_moves.r = a->top - pos.below;
	below_moves.rr = pos.below + 1;
	below_moves.cost = ft_min(below_moves.r, below_moves.rr);
	return (lowest_moves(above_moves, below_moves));
}

t_moves	get_moves_in_b(t_stack *b, int i)
{
	t_moves moves;

	moves.r = b->top - i;
	moves.rr = i + 1;
	moves.cost = ft_min(moves.r, moves.rr);
	return (moves);
}

void	reset_insts(t_insts *insts)
{
	insts->ra = 0;
	insts->rb = 0;
	insts->rra = 0;
	insts->rrb = 0;
	insts->rr = 0;
	insts->rrr = 0;
}

t_insts	get_same_dir_inst(t_moves a, t_moves b)
{
	t_insts insts;

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

t_insts	get_diff_dir_inst(t_moves a, t_moves b)
{
	t_insts insts;
	
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

int	get_insts_cost(t_insts insts, int bias)
{
	return (insts.ra + insts.rra + insts.rb
		+ insts.rrb + insts.rr + insts.rrr + bias);
}

t_insts	get_best_instructions(t_stack *a, t_stack *b, t_pos pos, int i)
{
	t_insts	same_dir;
	t_insts diff_dir;
	t_moves	a_moves;
	t_moves b_moves;

	a_moves = get_moves_in_a(a, pos);
	b_moves = get_moves_in_b(b, i);
	same_dir = get_same_dir_inst(a_moves, b_moves);
	diff_dir = get_diff_dir_inst(a_moves, b_moves);
	same_dir.cost = get_insts_cost(same_dir, 0);
	diff_dir.cost = get_insts_cost(diff_dir, 0);
	if (same_dir.cost < diff_dir.cost)
		return (same_dir);
	return (diff_dir);
}

void	execute_instructions(t_stack *a, t_stack *b, t_insts insts)
{
	while (insts.ra > 0)
	{
		ra(a);
		insts.ra--;
	}
	while (insts.rra > 0)
	{
		rra(a);
		insts.rra--;
	}
	while (insts.rb > 0)
	{
		rb(b);
		insts.rb--;
	}
	while (insts.rrb > 0)
	{
		rrb(b);
		insts.rrb--;
	}
	while (insts.rr > 0)
	{
		rr(a, b);
		insts.rr--;
	}
	while (insts.rrr > 0)
	{
		rrr(a, b);
		insts.rrr--;
	}
}

void	step(t_stack *a, t_stack *b, t_insts insts, t_pos pos, int i)
{
	char s[10];

	ft_printf("# Above[%d] %d [%d]Below\n", pos.above, b->values[i], pos.below);
	print_insts(insts);
	ft_stack_print(a, 'a');
	ft_stack_print(b, 'b');
	scanf("%5s", s);
}

void	_push_swap_cost(t_stack *a, t_stack *b)
{
	t_insts	min_insts;
	t_insts	insts;
	t_pos	pos;
	t_pos	min_pos;
	int		min_index;
	int		i;

	push_a_to_b(a, b);
	if (a->top == 2)
		sort_tiny_stack(a);
	while (b->top >= 0)
	{
		i = b->top;
		pos = _get_pos_in_a(a, b->values[i]);
		min_insts = get_best_instructions(a, b, pos, i);
		//debug to be deleted later
		min_pos = pos;
		min_index = i;
		//
		while (i >= 0)
		{
			pos = _get_pos_in_a(a, b->values[i]);
			insts = get_best_instructions(a, b, pos, i);
			if (insts.cost < min_insts.cost)
			{
				min_insts = insts;
				//debug to be deleted later
				min_pos = pos;
				min_index = i;
				//
			}
			i--;
		}
		//step(a, b, min_insts, min_pos, min_index);
		execute_instructions(a, b, min_insts);
		pa(a, b);
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
///////////////////////////////////////////////////////////////////////////////////

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
		if (arr[0] < arr[1])
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

void	push_swap(t_stack *a, t_stack *b)
{
	if (ft_stack_sorted(a))
		return ;
	if (a->top < 5)
		return push_swap_small(a, b);
	else
		return _push_swap_cost(a, b);
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
			_push_swap_cost(a, b);
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
#ifdef CONSOLE
	push_swap_console(a, b);
#else
	push_swap(a, b);
#endif
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
