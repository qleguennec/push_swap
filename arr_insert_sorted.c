/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_insert_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:03:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/17 10:34:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void		arr_insert_sorted
	(long *arr, long x, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && arr[i] != ((long)INT_MAX + 1) && arr[i] < x)
		i++;
	if (arr[i] != ((long)INT_MAX + 1))
		ft_memmove(&arr[i + 1], &arr[i], (size - i - 1) * sizeof(long));
	arr[i] = x;
}
