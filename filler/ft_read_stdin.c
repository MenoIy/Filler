/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:31:14 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 15:40:43 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_stock_table(int n, int plus)
{
	char	*line;
	int		i;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (n + 1))))
		return (0);
	i = -1;
	while (get_next_line(0, &line) > 0)
	{
		if ((ft_strncmp(line, "0", 1) == 0 && plus == 4) || plus == 0)
			if (!(tab[++i] = ft_strdup(line + plus)))
			{
				ft_free_table(&tab);
				ft_strdel(&line);
				return (0);
			}
		ft_strdel(&line);
		if (i == n - 1)
			break ;
	}
	tab[n] = NULL;
	return (tab);
}

static int	ft_read_table(t_filler *filler, char **line)
{
	filler->tab_line = ft_atoi(*line + 8);
	filler->tab_col = ft_atoi(*line + 11);
	if (!(filler->tab = ft_stock_table(filler->tab_line, 4)))
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}

static int	ft_read_piece(t_filler *filler, char **line)
{
	filler->piece_line = ft_atoi(*line + 6);
	filler->piece_col = ft_atoi(*line + 8);
	if (!(filler->piece = ft_stock_table(filler->piece_line, 0)))
	{
		ft_strdel(line);
		return (0);
	}
	ft_strdel(line);
	return (1);
}

static void	ft_change_player(t_filler *filler)
{
	filler->player = 'X';
	filler->enemi = 'O';
}

int			ft_read_stdin(t_filler *filler)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
			ft_change_player(filler);
		if (ft_strncmp(line, "Plateau", 7) == 0)
			if (!(ft_read_table(filler, &line)))
				return (0);
		if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (!(ft_read_piece(filler, &line)))
			{
				ft_free_table(&filler->tab);
				return (0);
			}
			else
				return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}
