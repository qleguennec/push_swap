/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 21:46:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	err
	(void)
{
	ft_putendl("Error");
	return (1);
}

int			main
	(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**start;

	if (argc < 2)
		err();
	start = argv + 1;
	if (!(a = build_stack(start, argv + argc - 1)))
		return (err());
	b = NULL;
	return (0);
}
