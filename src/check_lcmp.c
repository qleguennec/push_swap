/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 09:43:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/26 20:50:06 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			check_lcmp
	(int x, t_lst *a, t_lst *cmp)
{
	int		res;

	if (!a)
		return (1);
	res = lcmp(a, cmp);
	if (!x && res)
		return (0);
	if (SIGN(x) != SIGN(res))
		return (0);
	return (check_lcmp(x, a->next, cmp));
}
