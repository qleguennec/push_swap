/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 22:03:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	err(void)
{
	ft_putendl("Error");
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**start;
	int		d;

	if (argc < 2)
		err();
	if (ft_strequ(argv[1], "-d"))
	{
		d = 1;
		start = argv + 2;
	}
	else
		start = argv + 1;
	if (!(a = build_stack(start, argv + argc - 1)))
		return err();
	b = NULL;
	if (d)
		return (debug(&a, &b));
	return (0);
}
