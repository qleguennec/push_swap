/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:11:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 21:57:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

static int		isvalid_value
	(long x)
{
	return (x >= INT_MIN && x <= INT_MAX);
}

static long		atol
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
	(char **start, char **end)
{
	t_list		*l;
	t_list		*ret;

	ret = NULL;
	while (end >= start)
	{
		if (ft_strlen(*end) > 11)
			return (NULL);
		if (!(l = ft_memalloc(sizeof(*l))))
			return (NULL);
		l->data = (void *)atol(*end);
		if (!isvalid_value((long)l->data))
			return (NULL);
		ft_lstadd(&ret, l);
		end--;
	}
	return (ret);
}
