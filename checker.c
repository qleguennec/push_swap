/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 01:44:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libgnl/libgnl.h"
#include "push_swap.h"
#include <stdlib.h>

static void		read_input
	(t_stack *a, t_stack *b, int opts)
{
	char		*line;
	t_stack_op	*op;
	int			ret;
	void		*fst;
	void		*lst;

	fst = g_stack_ops;
	lst = fst + sizeof(*op) * (LEN(g_stack_ops) - 1);
	if (opts & 1)
		stack_display_both(a, b);
	while ((ret = get_next_line(0, &line)) >= 0)
	{
		if (!ret)
			break ;
		if (ret < 0 || ft_strlen(line) > 3)
			ps_exit();
		if (!ft_strcmp(line, ""))
			break ;
		if (!(op = ft_find(line, fst, lst, sizeof(*op))))
			ps_exit();
		ft_putendl(line);
		ft_memdel((void **)&line);
		stack_apply_op(op, a, b);
		if (opts & 1)
			stack_display_both(a, b);
	}
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

int				main
	(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	int			opts;

	if (argc < 2)
		ps_exit();
	args = get_args(argc, argv);
	opts = 0;
	if (*args && !ft_strcmp(*args, "-v") && args++)
		opts += 1;
	a = stack_build(args);
	if (!(b = ft_memalloc(sizeof(*b))))
		ps_exit();
	read_input(a, b, opts);
	if (sorted(b->head))
	{
		ft_putendl("OK");
		return (0);
	}
	else
		ft_putendl("KO");
	return (1);
}
