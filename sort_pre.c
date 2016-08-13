/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 22:36:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/17 10:35:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long		*sort_pre
	(t_node *n, size_t size)
{
	size_t	i;
	long	*ret;

	if (!(ret = ft_memalloc(sizeof(*ret) * size)))
		ps_exit();
	i = 0;
	while (i < size)
		ret[i++] = ((long)INT_MAX) + 1;
	while (n)
	{
		arr_insert_sorted(ret, n->data, size);
		n = n->next;
	}
	return (ret);
}
