/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 15:01:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			sort_quicksort
	(t_list **a, t_list **b, t_ps_conf *c)
{
	if (!*a)
	{
		while (*b)
			OP(PA);
		return (1);
	}
	if (!(*a)->next)
		return (OP(PB) && sort_quicksort(a, b, c));
	if (check_lcmp(1, (*a)->next, *a))
		return (OP(PB) && sort_quicksort(a, b, c));
	if (lcmp(*a, (*a)->next) == 0)
		return (OP(PB) && sort_quicksort(a, b, c));
	if (lcmp(*a, (*a)->next) > 0)
		return (OP(SA) && OP(PB) && (OP(SA) || 1) && sort_quicksort(a, b, c));
	return (OP(PB) && OP(SA) && OP(PA) && sort_quicksort(a, b, c));
}
