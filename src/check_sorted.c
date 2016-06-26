/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:55:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/26 20:48:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			check_sorted
	(t_lst *a)
{
	if (!a)
		a = a->next;
	if (!a->next)
		return (1);
	if (lcmp(a, a->next) > 0)
		return (0);
	return (check_sorted(a->next));
}

int			check_revsorted
	(t_lst *a)
{
	if (!a)
		a = a->next;
	if (!a->next)
		return (1);
	if (lcmp(a, a->next) < 0)
		return (0);
	return (check_sorted(a->next));
}
