/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:03:10 by inajah            #+#    #+#             */
/*   Updated: 2024/12/01 17:21:48 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int top;
	int	*values;
}	t_stack;

void	ft_stack_swap(t_stack *s);
void	ft_stack_push(t_stack *src, t_stack *dst);
void	ft_stack_rotate(t_stack *s);
void	ft_stack_rrotate(t_stack *s);

#endif
