/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:20:51 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 16:02:04 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void	ft_print_result(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

static int	ft_play_filler(t_filler *filler)
{
	while (1)
	{
		if (!ft_read_stdin(filler) || !filler->tab || !filler->piece)
			return (0);
		if (ft_filler(filler))
			ft_print_result((int)filler->out.y - filler->miny,
					(int)filler->out.x - filler->minx);
		else
			ft_print_result(0, 0);
		ft_free_table(&(filler->tab));
		ft_free_table(&(filler->piece));
		ft_filler_init(&filler, 0);
	}
	return (1);
}

int			main(void)
{
	t_filler	*filler;

	if (!(ft_filler_init(&filler, 1)))
		return (1);
	ft_play_filler(filler);
	ft_memdel((void *)&filler);
	return (0);
}
