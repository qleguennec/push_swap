/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 09:43:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/07 20:27:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			cmp
	(t_node *a, t_node *b)
{
	assert(a && b);
	if (a->data == b->data)
		return (0);
	if (a->data < b->data)
		return (-1);
	return (1);
}

int			cmp_back
	(int x, t_node *a, t_node *b)
{
	int		res;

	if (!a)
		return (1);
	res = cmp(a, b);
	if (!x && res)
		return (0);
	if (!res && x)
		return (cmp_back(x, a->prev, b));
	if (SIGN(x) != SIGN(res))
		return (0);
	return (cmp_back(x, a->prev, b));
}

int			cmp_front
	(int x, t_node* a, t_node *b)
{
	int		res;

	if (!a)
		return (1);
	res = cmp(a, b);
	if (!x && res)
		return (0);
	if (!res && x)
		return (cmp_front(x, a->next, b));
	if (SIGN(x) != SIGN(res))
		return (0);
	return (cmp_front(x, a->next, b));
}

int			sorted
	(t_node *n)
{
	if (!n || !n->next)
		return (1);
	if (cmp(n, n->next) > 0)
		return (0);
	return (sorted(n->next));
}

int			rev_sorted
	(t_node *n)
{
	if (!n || !n->next)
		return (1);
	if (cmp(n, n->next) < 0)
		return (0);
	return (rev_sorted(n->next));
}
