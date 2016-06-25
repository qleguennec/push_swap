/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 02:46:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 15:15:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			lcmp
	(t_list *a, t_list *b)
{
	long	*x;
	long	*y;

	x = a->data;
	y = b->data;
	if (*x == *y)
		return (0);
	if (*x > *y)
		return (1);
	return (-1);
}
