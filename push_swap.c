/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/17 13:03:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char		**get_args
	(int argc, char **argv)
{
	size_t		i;
	char		**ret;

	argc--;
	argv++;
	i = 0;
	if (!(ret = ft_memalloc(sizeof(*ret) * (argc + 1))))
		ps_exit();
	while (i < (size_t)argc)
	{
		if (!(ret[i] = ft_strdup(argv[i])))
			ps_exit();
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static int		ps_main
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	size_t		i;

	i = 0;
	while (i < a->size)
	{
		ft_printf("%d%c", c->sorted[i], i + 1 == a->size ? '\n' : ' ');
		i++;
	}
	sort_quick(a, b, c);
	return (0);
}

int				main
	(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	t_ps_conf	c;

	if (argc < 2)
		ps_exit();
	args = get_args(argc, argv);
	ft_bzero(&c, sizeof(c));
	a = stack_build(args);
	c.sorted = sort_pre(a->head, a->size);
	if (!(b = ft_memalloc(sizeof(*b))))
		ps_exit();
	if (!(c.log = ft_memalloc(sizeof(*c.log))))
		ps_exit();
	if (!vect_req(c.log, a->size * sizeof(int)))
		ps_exit();
	return (ps_main(a, b, &c));
}
