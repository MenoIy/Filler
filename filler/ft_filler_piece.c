/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 08:48:37 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 15:59:25 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_piece_limits(t_filler *filler)
{
	int	i;
	int	j;

	j = -1;
	while (filler->piece[++j])
	{
		i = -1;
		while (filler->piece[j][++i])
		{
			if (filler->piece[j][i] == '*')
			{
				if (i < filler->minx)
					filler->minx = i;
				if (j < filler->miny)
					filler->miny = j;
				filler->piece_size++;
			}
		}
	}
}

t_point		*ft_filler_piece(t_filler *filler)
{
	t_point	*p;
	int		i;
	int		j;
	int		x;

	j = -1;
	x = -1;
	ft_piece_limits(filler);
	if (!(p = (t_point *)malloc(sizeof(t_point) * (filler->piece_size + 1))))
		return (NULL);
	while (filler->piece[++j])
	{
		i = -1;
		while (filler->piece[j][++i])
			if (filler->piece[j][i] == '*')
				p[++x] = ft_new_point(i - filler->minx, j - filler->miny);
	}
	return (p);
}
