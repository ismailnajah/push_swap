/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/01 11:06:03 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stack
{
	int top;
	int	*values;
}	t_stack;

int	ft_perror(char *msg)
{
	if (msg)
		write(STDERR, msg, ft_strlen(msg));
	return (1);
}

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
	s->top = size - 1;
	s->values = malloc(size * sizeof(int));
	if (!s->values)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

int	ft_is_valid_arg(char *arg, int *out)
{
	int	i;
	long result;
	int	sign;

	i = 0;
	sign = (arg[i] == '-');
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (!arg[i + 1])
			return (FALSE);
		i++;
	}
	result = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		if (result > (MAX_INT + sign - (arg[i] - '0')) / 10)
			return (FALSE); 
		result = result * 10 + (arg[i] - '0');
		i++;
	}
	*out = result * (1 - 2 * sign);
	return (TRUE);
}

t_stack	*ft_parse_args(int ac, char **av)
{
	t_stack *s;
	int		value;
	int		i;
	int		j;

	s = ft_stack_init(ac);
	if (!s)
		return (NULL);
	i = s->top;
	while (i >= 0)
	{
		if (!ft_is_valid_arg(av[s->top - i], &value))
			return (ft_stack_free(s));
		j = s->top;
		while (j > i)
		{
			if (s->values[j] == value)
				return (ft_stack_free(s));
			j--;
		}
		s->values[i] = value;
		i--;
	}
	return (s);
}

int	main(int ac, char **av)
{
	t_stack	*s;
	int		i;

	if (ac == 1)
		return (1);
	s = ft_parse_args(ac - 1, av + 1);
	if (!s)
		return (ft_perror("Error\n"));
	i = s->top;
	ft_printf("stack : [ ");
	while (i >= 0)
	{
		ft_printf("%d ", s->values[i]);
		i--;
	}
	ft_printf("]\n");
	return (0);
}

