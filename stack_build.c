/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:11:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 00:24:45 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
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

t_stack			*stack_build
	(char **arg)
{
	t_stack		*s;
	t_node		*l;
	long		x;

	if (!(s = ft_memalloc(sizeof(*s))))
		ps_exit();
	while (*arg)
	{
		x = ft_atol(*arg);
		if (!isvalid_value(x))
			ps_exit();
		l = s->last;
		if (!(s->last = ft_memalloc(sizeof(*l))))
			ps_exit();
		s->last->data = (int)x;
		if (!s->head)
			s->head = l;
		if (l)
			l->next = s->last;
		s->last->prev = l;
		arg++;
		s->size++;
	}
	return (s);
}
