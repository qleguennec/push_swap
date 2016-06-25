/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 04:54:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		sort_quicksort
	(t_list **a, t_list **b, t_ps_conf *c)
{
	long	pivot;

	pivot = (long)(*a)->data;
	apply(RA | 2, a, b, c);
	apply(SA, a, b, c);
	apply(SS, a, b, c);
}
