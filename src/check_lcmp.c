/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 09:43:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 09:46:07 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			check_lcmp
	(int x, t_list *a, t_list *cmp)
{
	if (!a)
		return (1);
	if (x != lcmp(a, cmp))
		return (0);
	return (check_lcmp(x, a->next, cmp));
}
