/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:03:10 by inajah            #+#    #+#             */
/*   Updated: 2024/12/02 09:30:19 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

//ft_stack_operations.c
void	ft_stack_swap(t_stack *s);
void	ft_stack_push(t_stack *src, t_stack *dst);
void	ft_stack_rotate(t_stack *s);
void	ft_stack_rrotate(t_stack *s);

#endif
