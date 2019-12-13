/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:37:54 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 15:44:23 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_mlx.h"

void	ft_draw_grid(t_filler *filler, int x, int y)
{
	int	j;
	int	i;
	int	max_j;
	int	max_i;

	max_i = x * filler->scale + filler->center;
	max_j = y * filler->scale + filler->center;
	i = filler->center;
	while (i <= max_i)
	{
		j = filler->center - 1;
		while (++j < max_j)
			ft_draw_img(filler->setup, i, j, ft_color_create(255, 255, 255, 0));
		i += filler->scale;
	}
	j = filler->center;
	while (j <= max_j)
	{
		i = filler->center - 1;
		while (++i < max_i)
			ft_draw_img(filler->setup, i, j, ft_color_create(255, 255, 255, 0));
		j += filler->scale;
	}
}

void	ft_fill_square(t_filler *filler, int x, int y, t_color color)
{
	int	i;
	int	j;
	int	max_j;
	int	max_i;

	max_i = (x + 1) * filler->scale + filler->center;
	max_j = (y + 1) * filler->scale + filler->center;
	i = x * filler->scale + 1 + filler->center;
	while (i < max_i)
	{
		j = y * filler->scale + 1 + filler->center;
		while (j < max_j)
		{
			ft_draw_img(filler->setup, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_fill_progression(t_setup *setup, int x, int y, t_color color)
{
	int	i;
	int	j;

	j = y;
	while (++j < y + 20)
	{
		i = 0;
		while (++i < x * 8)
			ft_draw_img(setup, i, j, color);
	}
}
