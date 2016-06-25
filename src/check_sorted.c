/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 02:58:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			check_sorted
	(t_list *a)
{
	if (!a)
		a = a->next;
	if (!a->next)
		return (1);
	if (lcmp(a, a->next) > 0)
		return (0);
	return (check_sorted(a->next));
}
