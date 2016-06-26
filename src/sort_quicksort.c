/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/26 20:44:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	sort_small
	(t_stack *a, t_stack *b, t_ps_conf *c, t_lst *piv)
{
	if (a->last == piv)
		return (OP(RRA) && OP(PB) && OP(RB));
	if (lcmp(piv, a->head) <= 0)
		return (OP(RRA) && sort_small(a, b, c, piv));
	else
		return (OP(PB) && sort_small(a, b, c, piv));
}

static int	sort_big
	(t_stack *a, t_stack *b, t_ps_conf *c, t_lst *piv)
{
	if (a->head == piv)
		return (OP(PA) && OP(RA));
	if (lcmp(piv, b->head) >= 0)
		return (OP(RRB) && sort_big(a, b, c, piv));
	else
		return (OP(PA) && sort_big(a, b, c, piv));
}

int			sort_quicksort
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_lst	*piv;

	piv = a->head;
	sort_small(a, b, c, piv);
	sort_big(a, b, c, piv);
	return (b->head ? sort_quicksort(a, b, c) : 1);
}
