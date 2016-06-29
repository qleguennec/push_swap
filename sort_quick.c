/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 12:20:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 00:46:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

int sort_a(t_stack*, t_stack*, t_ps_conf *c);

int			sort_b
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_node	*cmp_node;

	assert(b && b->head);
	cmp_node = b->head;
	if (cmp_front(-1, cmp_node->next, cmp_node))
		return (1);
	OP(SB);
	assert(b->head->next == cmp_node);
	if (cmp(cmp_node, cmp_node->prev) < 0)
		return (OP(PA) && sort_b(a, b, c));
	return (OP(RRB) && sort_b(a, b, c));
}

int			sort_a
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_node	*cmp_node;

	assert(a && a->head);
	cmp_node = a->head;
	if (cmp_front(1, cmp_node->next, cmp_node))
		return (1);
	OP(SA);
	assert(a->head->next == cmp_node);
	if (cmp(cmp_node, cmp_node->prev) >= 0)
		return (OP(PB) && sort_b(a, b, c) && sort_a(a, b, c));
	return (OP(RRA) && sort_a(a, b, c));
}

int			sort_quick
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_node	*cmp_node_a;

	cmp_node_a = a->head;
	while (a->head)
	{
		sort_a(a, b, c);
		OP(PB);
		sort_b(a, b, c);
	}
	return (1);
}
