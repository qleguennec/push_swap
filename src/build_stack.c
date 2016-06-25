/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:11:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 15:13:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

static int		isvalid_value
	(long x)
{
	return (x >= INT_MIN && x <= INT_MAX);
}

static long		ft_atol
	(char *s)
{
	size_t		pow;
	long		ret;
	int			neg;

	ret = 0;
	neg = (*s == '-') ? 1 : 0;
	if (neg)
		s++;
	pow = ft_pow(10, (ft_strlen(s) - 1));
	while (*s)
	{
		if (!ft_isdigit(*s))
			return ((long)INT_MAX + 1);
		ret += pow * (*s - '0');
		pow /= 10;
		s++;
	}
	return (neg ? - ret : ret);
}

t_list			*build_stack
	(char **arg)
{
	t_list		*l;
	long		x;

	if (!*arg)
		return (NULL);
	x = ft_atol(*arg);
	if (!isvalid_value(x))
		ps_exit();
	if (!(l = ft_lstnew(&x, sizeof(x))))
		ps_exit();
	l->next = build_stack(arg + 1);
	return (l);
}
