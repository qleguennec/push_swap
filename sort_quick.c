/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 12:20:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/26 15:51:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_pivot
	(long x)
{
	int a = x & ((long)1) << (sizeof(long) * 8 - 1);
	return (a);
}

static t_node	*get_node_offset
	(t_node *n, int offset, t_ps_conf *c)
{
	c->sorted[offset] |= ((long)1) << (sizeof(long) * 8 - 1);
	while (offset)
	{
		n = SIGN(offset) ? n->prev : n->next;
		offset += SIGN(offset) ? 1 : -1;
	}
	return (n);
}

static t_node	*get_pivot
	(t_node *n, size_t size, t_ps_conf *c)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size && is_pivot(c->sorted[i]))
		i++;
	if (i == size - 1)
		return (NULL);
	j = i ? i : 1;
	while (j * 2 < size && is_pivot(c->sorted[j * 2]))
		j++;
	if (!is_pivot(c->sorted[j * 2]))
		return (get_node_offset(n, j * 2, c));
	j = i ? i : 1;
	while (j && ((int)j) / 2 >= 0 && is_pivot(c->sorted[j / 2]))
		j--;
	if (!is_pivot(c->sorted[j / 2]))
		return (get_node_offset(n, j / 2, c));
	return (NULL);
}

static int		sort
	(t_stack *a, t_stack *b, t_ps_conf *c, t_node *piv)
{
	if (cmp_front(1, a->head, piv))
		return (1);
	return (OP(cmp(a->head, piv) < 0 ? PB : RRA) && sort(a, b, c, piv));
}

int				sort_quick
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_node		*piv;

	piv = get_pivot(a->head, a->size, c);
	if (!piv)
		return (1);
	sort(a, b, c, piv);
	while (b->head)
		OP(PA);
	return (sort_quick(a, b, c));
}
