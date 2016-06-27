/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/27 13:55:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libgnl.h>
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
	if (!(c->log = ft_memalloc(sizeof(*c->log))))
		ps_exit();
	sort_quicksort(a, b, c);
	printf("total number of operations: %lu\n", c->log->used);
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
	if (*args && !ft_strcmp(*args, "-v") && args++)
		c.verbose = 1;
	a = build_stack(args);
	if (!(b = ft_memalloc(sizeof(*b))))
		ps_exit();
	return (ps_main(a, b, &c));
}
