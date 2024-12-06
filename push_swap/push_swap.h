/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:03:10 by inajah            #+#    #+#             */
/*   Updated: 2024/12/06 18:01:05 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_insts
{
	int ra;
	int rb;
	int rra;
	int rrb;
	int rr;
	int rrr;
	int	cost;
}	t_insts;

typedef struct s_moves
{
	int r;
	int rr;
	int cost;
}	t_moves;

typedef struct s_pos
{
	int above;
	int below;
}	t_pos;

typedef struct s_stack
{
	int	top;
	int	*values;
}	t_stack;

//ft_parse.c
char	**ft_get_args(int ac, char **av);
t_stack	*ft_parse_args(int ac, char **av);

//ft_stack.c
t_stack	*ft_stack_init(int size);
void	*ft_stack_free(t_stack *s);
void	ft_stack_print(t_stack *s, char c);
void get_sorted_array_index(t_stack *a);

//ft_stack_operations.c
void	ft_stack_swap(t_stack *s);
void	ft_stack_push(t_stack *dst, t_stack *src);
void	ft_stack_rotate(t_stack *s);
void	ft_stack_rrotate(t_stack *s);

//ft_utils.c
int	*get_lds(t_stack *a);
int	get_seq_len(int *seq, int size);
#endif
