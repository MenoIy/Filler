/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:29:50 by kdaou             #+#    #+#             */
/*   Updated: 2019/08/05 08:55:02 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_del(void *content, size_t size)
{
	char	**tab;

	tab = (char **)content;
	(void)size;
	ft_free_table(&(tab));
}

void		ft_exit_management(t_filler *filler)
{
	mlx_destroy_image(filler->setup->mlx_ptr, filler->setup->img_ptr);
	mlx_clear_window(filler->setup->mlx_ptr, filler->setup->win_ptr);
	while (filler->tab_list && filler->tab_list->previous)
		filler->tab_list = filler->tab_list->previous;
	while (filler->piece_list && filler->piece_list->previous)
		filler->piece_list = filler->piece_list->previous;
	ft_memdel((void **)(&filler->setup));
	ft_lstdel(&(filler->tab_list), &ft_del);
	ft_lstdel(&(filler->piece_list), &ft_del);
	ft_memdel((void **)&filler);
	exit(1);
}
