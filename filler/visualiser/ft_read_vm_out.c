/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_vm_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:12:56 by kdaou             #+#    #+#             */
/*   Updated: 2019/08/05 08:52:27 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_read_table(t_filler *filler, char **line)
{
	char	**tab;

	filler->tab_line = ft_atoi(*line + 8);
	filler->tab_col = ft_atoi(*line + 11);
	if (!(tab = ft_stock_table(filler->tab_line, 4)))
	{
		ft_strdel(line);
		return (0);
	}
	ft_dbllstadd_end(&filler->tab_list, ft_dbllstnew(tab, 0));
	return (1);
}

static int	ft_read_piece(t_filler *filler, char **line)
{
	char	**tab;

	filler->piece_line = ft_atoi(*line + 6);
	filler->piece_col = ft_atoi(*line + 8);
	if (!(tab = ft_stock_table(filler->piece_line, 0)))
	{
		ft_strdel(line);
		return (0);
	}
	ft_dbllstadd_end(&filler->piece_list, ft_dbllstnew(tab, 0));
	ft_strdel(line);
	return (1);
}

static void	ft_change_player(t_filler *filler)
{
	filler->player = 'X';
	filler->enemi = 'O';
}

int			ft_read_vm_out(t_filler *filler)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$ exec p2", 11) == 0 &&
				ft_strpos(line, "kdaou"))
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
