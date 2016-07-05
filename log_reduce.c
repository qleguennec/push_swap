/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 14:49:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 02:39:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	log
	(int new, t_vect *l)
{
	return (vect_add(l, &new, sizeof(new)));
}

int			log_reduce
	(int new, t_vect *l)
{
	int		*last;

	if (!l->used)
		return (log(new, l));
	last = l->data + l->used - 4;
	if ((*last == PA && new == PB) || (*last == PB && new == PA))
		l->used -= 4;
	else if ((*last == SB && new == SA) || (*last == SA && new == SB))
		*last = SS;
	else if ((*last == RRB && new == RRA) || (*last == RRA && new == RRB))
		*last = RRR;
	else
		return (log(new, l));
	return (1);
}
