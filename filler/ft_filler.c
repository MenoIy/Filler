/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 08:51:54 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 16:02:09 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_fill_score(t_filler *filler, int x, int y, char score)
{
	int	i;
	int	j;
	int	done;

	j = y - 2;
	done = 0;
	while (++j <= y + 1)
	{
		i = x - 2;
		while (++i <= x + 1)
		{
			if (i < filler->tab_col && j < filler->tab_line)
				if (i >= 0 && j >= 0 && filler->tab[j][i] == '.')
				{
					filler->tab[j][i] = score;
					done = 1;
				}
		}
	}
	return (done);
}

static void	ft_score_map(t_filler *filler)
{
	int		i;
	int		j;
	int		x;
	char	score;
	char	target;

	x = -1;
	score = -1;
	target = filler->enemi;
	while (++x <= filler->tab_col)
	{
		j = -1;
		while (filler->tab[++j])
		{
			i = -1;
			while (filler->tab[j][++i])
			{
				if (filler->tab[j][i] == target)
					ft_fill_score(filler, i, j, score);
			}
		}
		target = score;
		score--;
	}
}

static int	ft_filler_score(t_filler *filler, t_point *point, int x, int y)
{
	int	i;
	int tot;
	int a;
	int	b;

	i = -1;
	tot = 0;
	while (++i < filler->piece_size)
	{
		a = x + point[i].x;
		b = y + point[i].y;
		if (a >= 0 && b >= 0)
			if (a < filler->tab_col && b < filler->tab_line)
				if (filler->tab[b][a] < 0)
					tot += filler->tab[b][a];
	}
	if (tot > filler->score && tot != 0)
	{
		filler->score = tot;
		return (1);
	}
	return (0);
}

static int	ft_is_placable(t_filler *filler, t_point *point, int x, int y)
{
	int	i;
	int touch;
	int a;
	int b;

	i = -1;
	touch = 0;
	while (++i < filler->piece_size)
	{
		a = x + point[i].x;
		b = y + point[i].y;
		if (a >= filler->tab_col || b >= filler->tab_line || a < 0 || b < 0)
			return (0);
		if (filler->tab[b][a] == filler->player)
			touch++;
		if (filler->tab[b][a] == filler->enemi || touch > 1)
			return (0);
	}
	if (touch == 1)
	{
		filler->isplaced = 1;
		filler->out = filler->score == -1e3 ? ft_new_point(x, y) : filler->out;
	}
	return (touch == 1 ? 1 : 0);
}

int			ft_filler(t_filler *filler)
{
	t_point	*p;
	int		i;
	int		j;

	if (!(p = ft_filler_piece(filler)))
		return (0);
	ft_score_map(filler);
	j = -1;
	while (filler->tab[++j])
	{
		i = -1;
		while (filler->tab[j][++i])
		{
			if (ft_is_placable(filler, p, i, j))
			{
				if (ft_filler_score(filler, p, i, j))
					filler->out = ft_new_point(i, j);
			}
		}
	}
	ft_memdel((void *)&p);
	return (filler->isplaced);
}
