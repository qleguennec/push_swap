/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 04:21:50 by qle-guen         ###   ########.fr       */
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
	(t_list **a, t_list **b, t_ps_conf *c)
{
	if (!(c->log = ft_memalloc(sizeof(*c->log))))
		ps_exit();
	sort_quicksort(a, b, c);
	return (0);
}

int				main
	(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	char		**args;
	t_ps_conf	*c;

	if (argc < 2)
		ps_exit();
	args = get_args(argc, argv);
	if (!(c = ft_memalloc(sizeof(*c))))
		ps_exit();
	if (*args && !ft_strcmp(*args, "-v") && args++)
		c->verbose = 1;
	a = build_stack(args);
	b = NULL;
	c->n_elems = ft_lstsize(a);
	return (ps_main(&a, &b, c));
}
