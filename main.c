/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:37:03 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/28 15:48:26 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool
	init_stacks
	(char **argv
	, t_vect *sa)
{
	bool	neg;
	t_i32	y;
	t_u64	x;

	vect_init(sa);
	while (*argv)
	{
		if ((neg = **argv == '-'))
			(*argv)++;
		if (!STRONLY(*argv, DIGIT) || ft_strlen(*argv) > 10)
			return (false);
		x = 0;
		STRTOB10(*argv, x);
		if ((neg || x <= INT_MAX) && (!neg || -(t_i64)x >= INT_MIN))
		{
			y = neg ? -x : x;
			VECT_ADD(sa, y);
		}
		else
			return (false);
		argv++;
	}
	return (true);
}

int
	main
	(int argc
	, char **argv)
{
	t_vect	sa;
	t_vect	sb;
	t_vect	sorted;

	(void)argc;
	if (!init_stacks(argv + 1, &sa))
		return (ERR(PARSE_ERR, 1, 0));
	vect_init(&sb);
	vect_init(&sorted);
	vect_req(&sb, sa.used);
	vect_add(&sorted, sa.data, sa.used);
	ft_i32_qsort(sorted.data, sorted.used / sizeof(t_i32), 0);
	VECHO_I32(sorted);
	return (0);
}
