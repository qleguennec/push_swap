/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/17 11:46:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libgnl/libgnl.h"
#include <stdlib.h>

static void		main_loop
	(t_stack *a, t_stack *b, t_vect *gnl, t_ps_conf *c)
{
	t_stack_op	*op;
	int			ret;
	size_t		s;

	s = c->log->used;
	ret = get_next_line(0, gnl, c->log);
	if (ret < 0)
		ps_exit();
	if (!ret)
		return ;
	vect_mset_end(c->log, '\0', 1);
	if (!(op = FIND(c->log->data + s, g_stack_ops)))
		return ((void)ps_exit());
	stack_apply_op(op, a, b);
	((char *)c->log->data)[c->log->used - 1] = '\n';
	if (c->opts & 1)
		stack_display_both(a, b, c);
	else
		c->log->used = 0;
	main_loop(a, b, gnl, c);
}

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

static int		check_sorted
	(t_stack *a, t_stack *b)
{
	if (b->size || !sorted(a->head))
	{
		ft_printf("KO\n");
		return (1);
	}
	ft_printf("OK\n");
	return (0);
}

int				main
	(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_vect		gnl;
	char		**args;
	t_ps_conf	c;

	if (argc < 2)
		ps_exit();
	args = get_args(argc, argv);
	ft_bzero(&c, sizeof(c));
	if (*args && !ft_strcmp(*args, "-v") && args++)
		c.opts += 1;
	a = stack_build(args);
	if (!a->size || !(b = ft_memalloc(sizeof(*b)))
		|| !(c.log = ft_memalloc(sizeof(*c.log))))
		return (ps_exit());
	ft_bzero(&gnl, sizeof(gnl));
	main_loop(a, b, &gnl, &c);
	if (c.opts & 1)
		vect_print(1, c.log, 8192);
	return (check_sorted(a, b));
}
