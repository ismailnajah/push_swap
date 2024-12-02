/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:18:40 by inajah            #+#    #+#             */
/*   Updated: 2024/12/02 09:19:36 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_stack_free(t_stack *s)
{
	if (!s)
		return (NULL);
	free(s->values);
	free(s);
	return (NULL);
}

t_stack	*ft_stack_init(int size)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = -1;
	s->values = malloc(size * sizeof(int));
	if (!s->values)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

void	ft_stack_print(t_stack *s, char c)
{
	int	i;

	i = s->top;
	ft_printf("stack %c: [ ", c);
	while (i >= 0)
		ft_printf("%d ", s->values[i--]);
	ft_printf("]\n");
}
