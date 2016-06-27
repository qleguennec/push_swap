/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/27 14:14:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// TODO remove
void			piv_debug
	(t_stack *s, t_lst *piv)
{
	t_lst		*l;

	l = s->head;
	ft_putchar('\t');
	while (l)
	{
		if (l == piv)
			ft_putchar('*');
		else
			ft_putchar(l->next ? ' ' : '\n');
		l = l->next;
	}
}

/*
static int		sort_big
	(t_stack *a, t_stack *b, t_ps_conf *c, t_lst *piv)
{
	if (!piv)
		return (1);
	if (piv == a->head || !a->head->next)
		return (1);
	if (lcmp(piv, a->head) > 0)
		return (OP(PB) && sort_big(a, b, c, piv));
	else
		return (OP(RRA) && sort_big(a, b, c, piv));
}
*/
static int		sort_small
	(t_stack *a, t_stack *b, t_ps_conf *c, t_lst *piv)
{
	piv_debug(b, piv);
	if (!piv)
		return (1);
	if (piv == b->head || piv == b->last)
		return (1);
	if (lcmp(piv, b->head) >= 0)
		return (OP(PA) && sort_small(a, b, c, piv));
	else
		return (OP(RB) && sort_small(a, b, c, piv));
}

static t_lst	*select_piv
	(t_stack *s)
{
	size_t		size;
	t_lst		*ret;

	assert(s->head);
	assert(s->last);
	if (!s->head->next)
		return (NULL);
	if (s->size == 2)
		return (s->last);
	size = s->size / 2;
	ret = s->last;
	while (size--)
		ret = ret->prev;
	return (ret);
}

static int		sort
	(t_stack *a, t_stack *b, t_ps_conf *c, t_lst *piv)
{
	if (!piv)
		piv = select_piv(a);
	piv_debug(a, piv);
	if (piv != a->last && piv != a->head)
	{
		if (lcmp(piv, a->head) < 0)
			return (OP(PB) && sort(a, b, c, piv));
		else if (piv != a->last)
			return (OP(RA) && sort(a, b, c, piv));
	}
	if (b->head)
		sort_small(a, b, c, select_piv(b));
	return (1);
}

int				sort_quicksort
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	return (sort(a, b, c, NULL));
}
