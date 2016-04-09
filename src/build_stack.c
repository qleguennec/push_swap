/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:11:39 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 19:59:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

static int		isvalid_value
	(t_elem x)
{
	return (x >= INT_MIN && x <= INT_MAX);
}

static t_elem	atol
	(char *s)
{
	size_t		pow;
	t_elem		ret;
	int			neg;

	ret = 0;
	neg = (*s == '-') ? 1 : 0;
	if (neg)
		s++;
	pow = ft_pow(10, (ft_strlen(s) - 1));
	while (*s)
	{
		if (!ft_isdigit(*s))
			return ((t_elem)INT_MAX + 1);
		ret += pow * (*s - '0');
		pow /= 10;
		s++;
	}
	return (neg ? - ret : ret);
}

t_stack			*build_stack
	(char **start, char **end)
{
	t_list		*l;
	t_stack		*ret;

	ret = NULL;
	while (end >= start)
	{
		if (ft_strlen(*end) > 11)
			return (NULL);
		if (!(l = ft_memalloc(sizeof(*l))))
			return (NULL);
		l->content = (void *)atol(*end);
		if (!isvalid_value((t_elem)l->content))
			return (NULL);
		ft_lstadd(&ret, l);
		end--;
	}
	return (ret);
}
