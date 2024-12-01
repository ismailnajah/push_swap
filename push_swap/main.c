/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:01:56 by inajah            #+#    #+#             */
/*   Updated: 2024/12/01 16:50:30 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_is_valid_number(char *arg, int *out)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	if (!arg)
		return (FALSE);
	sign = (arg[i] == '-');
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (FALSE);
	result = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		if (result > ((long)MAX_INT + sign - (arg[i] - '0')) / 10)
			return (FALSE);
		result = result * 10 + (arg[i] - '0');
		i++;
	}
	*out = result * (1 - 2 * sign);
	return (TRUE);
}

t_stack	*ft_parse_args(int ac, char **av)
{
	t_stack	*s;
	int		value;
	int		i;
	int		j;

	s = ft_stack_init(ac);
	if (!s)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!ft_is_valid_number(av[ac - 1 - i], &value))
			return (ft_stack_free(s));
		j = 0;
		while (j < i)
		{
			if (s->values[j] == value)
				return (ft_stack_free(s));
			j++;
		}
		s->values[i] = value;
		i++;
	}
	return (s);
}

char	*ft_strjoin_with_sep(char *s1, char *s2, char *sep)
{
	char	*tmp;

	tmp = ft_strjoin(s1, sep);
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	return (s1);
}

int	ft_is_valid_arg(char *arg)
{
	int	i;

	if (!arg[0])
		return (FALSE);
	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	**ft_get_args(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	*merged;

	merged = ft_strdup("");
	if (!merged)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (!ft_is_valid_arg(av[i]))
			return (free(merged), NULL);
		tmp = ft_strjoin_with_sep(merged, av[i], " ");
		free(merged);
		if (!tmp)
			return (NULL);
		merged = tmp;
		i++;
	}
	av = ft_split(merged, ' ');
	return (free(merged), av);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	int	i;

	(void) b;
	i = a->top;
	ft_printf("stack a: [ ");
	while (i >= 0)
		ft_printf("%d ", a->values[i--]);
	ft_printf("]\n");
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
	ft_push_swap(a, b);
	ft_stack_free(b);
	ft_stack_free(a);
	return (0);
}
