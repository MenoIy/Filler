/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 07:52:55 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 18:26:14 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_draw_piece(t_filler *filler)
{
	char	**tab;
	int		j;
	t_point	*p;
	int		z[2];

	z[0] = 0;
	z[1] = 0;
	tab = filler->piece_list->content;
	filler->piece = tab;
	p = ft_filler_piece(filler);
	j = -1;
	while (++j < filler->piece_size)
	{
		z[0] = z[0] <= p[j].x ? p[j].x : z[0];
		z[1] = z[1] <= p[j].y ? p[j].y : z[1];
		ft_fill_square(filler, p[j].x, p[j].y, ft_color_create(0, 0, 255, 0));
	}
	ft_draw_grid(filler, z[0] + 1, z[1] + 1);
	ft_memdel((void **)&p);
	filler->piece = NULL;
	filler->minx = 100;
	filler->miny = 100;
	filler->piece_size = 0;
	filler->center = 0;
	filler->scale = 800 / filler->tab_col;
}

static void	ft_score_bare(t_filler *filler, int x, int y)
{
	int size;

	filler->center = 820;
	ft_draw_piece(filler);
	size = filler->tab_col * filler->tab_line;
	ft_fill_progression(filler->setup, (x * 100) / size, 800,
			ft_color_create(255, 0, 0, 0));
	ft_fill_progression(filler->setup, (y * 100) / size, 820,
			ft_color_create(0, 255, 0, 0));
}

void		ft_visualiser_launcher(t_filler *filler)
{
	int		i;
	int		j;
	char	**tab;
	int		x;
	int		y;

	tab = (char **)filler->tab_list->content;
	x = 0;
	y = 0;
	ft_draw_grid(filler, filler->tab_col, filler->tab_line);
	j = -1;
	while (tab[++j])
	{
		i = -1;
		while (tab[j][++i])
		{
			if (ft_toupper(tab[j][i]) == filler->enemi)
				ft_fill_square(filler, i, j, ft_color_fromint(RED + 0 * x++));
			if (ft_toupper(tab[j][i]) == filler->player)
				ft_fill_square(filler, i, j, ft_color_fromint(GREEN + 0 * y++));
		}
	}
	ft_score_bare(filler, x, y);
	mlx_put_image_to_window(filler->setup->mlx_ptr, filler->setup->win_ptr,
			filler->setup->img_ptr, 100, 10);
}
