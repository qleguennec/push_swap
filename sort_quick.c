/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 12:20:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 21:20:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

size_t		low
	(size_t size)
{
	int		ints[3];
	int		max;
	int		min;
	int		med;

	ints[0] = rand() % size;
	ints[1] = rand() % size;
	ints[2] = rand() % size;
	max = MAX(MAX(ints[0], ints[1]), ints[2]);
	min = MIN(MIN(ints[0], ints[1]), ints[2]);
	med = ints[0] ^ ints[1] ^ ints[2] ^ max ^ min;
	return (med);
}

t_node		*get_pivot
	(t_node *a, t_node *b, size_t low)
{
	t_node	*piv;

	piv = a->head;
	while (low)
	{
		if (piv)
		{
			piv = piv->next;
			low--;
		}
		else
			piv = b->head;
	}
}

int			sort
	(t_stack *a, t_stack *b, t_ps_conf *c, t_node *piv)
{
	if (piv == a->head)
		return (1);
	if (cmp(piv, a->head) >= 0)
		return (OP(PB) && sort_a(a, b, c, piv));
	return (OP(RRA) && sort_a(a, b, c, piv));
}

int			sort_quick
	(t_stack *a, t_stack *b, t_ps_conf *c, size_t size)
{
	size_t	low;
	t_node	*piv;

	low = low(a, b, size);
	sort(a, b, c, piv_a);
	if (sorted(a->head) && rev_sorted(b->head))
	{
		while (b->size)
			OP(PA);
		return (1);
	}
	return (sort_quick(a, b, c));
}
