/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:03:10 by inajah            #+#    #+#             */
/*   Updated: 2024/12/07 12:55:08 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define MIN_INDEX 1
# define MAX_INDEX 0

# define TOP 2
# define MID 1
# define BOT 0

typedef struct s_insts
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	cost;
}	t_insts;

typedef struct s_moves
{
	int	r;
	int	rr;
	int	cost;
}	t_moves;

typedef struct s_pos
{
	int	above;
	int	below;
}	t_pos;

typedef struct s_stack
{
	int	top;
	int	*values;
}	t_stack;

//push_swap_small.c
void	push_swap_small(t_stack *a, t_stack *b);
void	push_swap_small_helper(t_stack *a, t_stack *b, int i);

//push_swap_insts.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b, int iter);
void	rr(t_stack *a, t_stack *b, int iter);
void	rrr(t_stack *a, t_stack *b, int iter);

//push_swap_utils.c
void	push_a_to_b(t_stack *a, t_stack *b);
t_pos	get_pos_in_a(t_stack *a, int value);
int		ft_get_index(t_stack *s, int min_index);

//ft_insts.c
t_insts	get_best_insts(t_stack *a, t_stack *b, t_pos pos, int i);
void	execute_insts(t_stack *a, t_stack *b, t_insts insts);
void	reset_insts(t_insts *insts);

//ft_moves.c
t_moves	get_moves_in_a(t_stack *a, t_pos pos);
t_moves	get_moves_in_b(t_stack *b, int i);

//ft_parse.c
char	**ft_get_args(int ac, char **av);
t_stack	*ft_parse_args(int ac, char **av);

//ft_stack.c
t_stack	*ft_stack_init(int size);
void	*ft_stack_free(t_stack *s);
int		ft_stack_sorted(t_stack *s);
void	ft_stack_print(t_stack *s, char c);

//ft_stack_operations.c
void	ft_stack_swap(t_stack *s);
void	ft_stack_push(t_stack *dst, t_stack *src);
void	ft_stack_rotate(t_stack *s);
void	ft_stack_rrotate(t_stack *s);

//ft_utils.c
int		ft_swap(int *a, int *b);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
#endif
