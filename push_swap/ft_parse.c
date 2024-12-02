/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:15:00 by inajah            #+#    #+#             */
/*   Updated: 2024/12/02 09:24:00 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	s->top = i - 1;
	return (s);
}
