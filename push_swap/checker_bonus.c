/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:36:31 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 13:12:58 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_inst(t_insts *insts, char *inst_str)
{
	if (ft_strncmp(inst_str, "pa\n", 3) == 0)
		insts->pa = 1;
	else if (ft_strncmp(inst_str, "pb\n", 3) == 0)
		insts->pb = 1;
	else if (ft_strncmp(inst_str, "sa\n", 3) == 0)
		insts->sa = 1;
	else if (ft_strncmp(inst_str, "sb\n", 3) == 0)
		insts->sb = 1;
	else if (ft_strncmp(inst_str, "ss\n", 3) == 0)
		insts->ss = 1;
	else if (ft_strncmp(inst_str, "ra\n", 3) == 0)
		insts->ra = 1;
	else if (ft_strncmp(inst_str, "rra\n", 4) == 0)
		insts->rra = 1;
	else if (ft_strncmp(inst_str, "rb\n", 3) == 0)
		insts->rb = 1;
	else if (ft_strncmp(inst_str, "rrb\n", 4) == 0)
		insts->rrb = 1;
	else if (ft_strncmp(inst_str, "rr\n", 4) == 0)
		insts->rr = 1;
	else if (ft_strncmp(inst_str, "rrr\n", 4) == 0)
		insts->rrr = 1;
	else
		return (0);
	return (1);
}

int	get_insts_from_user(t_insts *insts)
{
	char	*inst_str;

	inst_str = get_next_line(0);
	if (!inst_str)
		return (0);
	if (!set_inst(insts, inst_str))
	{
		free(inst_str);
		return (-1);
	}
	return (1);
}

void	push_swap_checker(t_stack *a, t_stack *b)
{
	t_insts	insts;
	int		ret;

	ret = 1;
	while (ret == 1)
	{
		reset_insts(&insts);
		ret = get_insts_from_user(&insts);
		execute_insts(a, b, insts);
	}
	if (ret == -1)
		ft_perror("Error\n");
	else if (ft_stack_sorted(a) && b->top < 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
		return (ft_perror("Error\n"));
	size = ft_split_count(av);
	a = ft_parse_args(size, av);
	ft_split_free(av);
	if (!a)
		return (ft_perror("Error\n"));
	b = ft_stack_init(size);
	if (!b)
		return (ft_stack_free(a), ft_perror("Error\n"));
	push_swap_checker(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
