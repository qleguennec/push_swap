/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 12:20:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 02:59:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int sort_a(t_stack*, t_stack*, t_ps_conf *c, t_node *piv);

t_node		*pick_pivot
	(t_node *head, unsigned int size)
{
	int		ints[3];
	int		max;
	int		min;
	int		med;

	if (!head || size <= 1)
		return (NULL);
	ints[0] = rand() % size;
	ints[1] = rand() % size;
	ints[2] = rand() % size;
	max = MAX(MAX(ints[0], ints[1]), ints[2]);
	min = MIN(MIN(ints[0], ints[1]), ints[2]);
	med = ints[0] ^ ints[1] ^ ints[2] ^ max ^ min;
	while (med)
	{
		head = head->next;
		med--;
	}
	return (head);
}

int			sort_b
	(t_stack *a, t_stack *b, t_ps_conf *c, t_node *piv)
{
	if (piv == b->head)
		return (1);
	if (cmp(piv, b->head) < 0)
		return (OP(PA) && sort_b(a, b, c, piv));
	return (OP(RRB) && sort_b(a, b, c, piv));
}

int			sort_a
	(t_stack *a, t_stack *b, t_ps_conf *c, t_node *piv)
{
	if (piv == a->head)
		return (1);
	if (cmp(piv, a->head) >= 0)
		return (OP(PB) && sort_a(a, b, c, piv));
	return (OP(RRA) && sort_a(a, b, c, piv));
}

int			sort_quick
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_node	*piv_a;
	t_node	*piv_b;

	assert(a && b && c);
	piv_a = pick_pivot(a->head, a->size);
	piv_b = pick_pivot(b->head, b->size);
	if (piv_a)
		sort_a(a, b, c, piv_a);
	if (piv_b)
		sort_b(a, b, c, piv_b);
	if (sorted(a->head) && rev_sorted(b->head))
	{
		while (b->size)
			OP(PA);
		return (1);
	}
	return (sort_quick(a, b, c));
}
