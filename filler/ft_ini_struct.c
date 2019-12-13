/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:23:46 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 15:51:34 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_filler_init(t_filler **filler, int verbos)
{
	if (verbos)
	{
		if (!(*filler = (t_filler *)malloc(sizeof(t_filler))))
			return (0);
		(*filler)->player = 'O';
		(*filler)->enemi = 'X';
		(*filler)->scale = 0;
		(*filler)->piece_col = 0;
		(*filler)->piece_line = 0;
		(*filler)->tab_col = 0;
		(*filler)->tab_line = 0;
		(*filler)->center = 0;
		(*filler)->tab_list = NULL;
		(*filler)->piece_list = NULL;
		(*filler)->setup = NULL;
	}
	(*filler)->tab = NULL;
	(*filler)->piece = NULL;
	(*filler)->score = -1e3;
	(*filler)->minx = 100;
	(*filler)->miny = 100;
	(*filler)->piece_size = 0;
	(*filler)->isplaced = 0;
	return (1);
}

t_point	ft_new_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
