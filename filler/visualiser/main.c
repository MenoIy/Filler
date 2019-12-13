/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:52:22 by kdaou             #+#    #+#             */
/*   Updated: 2019/08/05 08:54:03 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_setup_init(t_filler **filler)
{
	t_setup	*setup;

	if (!(setup = (t_setup *)malloc(sizeof(t_setup))))
	{
		ft_memdel((void**)filler);
		return (0);
	}
	setup->mlx_ptr = mlx_init();
	setup->win_ptr = mlx_new_window(setup->mlx_ptr, 1800, 1800, "filler");
	setup->img_ptr = mlx_new_image(setup->mlx_ptr, 1700, 1700);
	setup->width = 1700;
	setup->height = 1700;
	setup->data = mlx_get_data_addr(setup->img_ptr, &(setup->bpp),
			&(setup->sizeline), &(setup->endian));
	(*filler)->setup = setup;
	return (1);
}

static int	ft_position_control(int key, t_filler *filler)
{
	if (key == 116)
	{
		while (filler->tab_list->next)
			filler->tab_list = filler->tab_list->next;
		while (filler->piece_list->next)
			filler->piece_list = filler->piece_list->next;
	}
	if (key == 121)
	{
		while (filler->tab_list->previous)
			filler->tab_list = filler->tab_list->previous;
		while (filler->piece_list->previous)
			filler->piece_list = filler->piece_list->previous;
	}
	return (1);
}

int			ft_remote_filler(int key, t_filler *filler)
{
	ft_mlx_clear_img(filler->setup, 1700, 1700);
	if (key == 53)
		ft_exit_management(filler);
	if (key == 124 && filler->tab_list->next)
	{
		filler->tab_list = filler->tab_list->next;
		filler->piece_list = filler->piece_list->next;
	}
	if (key == 123 && filler->tab_list->previous)
	{
		filler->piece_list = filler->piece_list->previous;
		filler->tab_list = filler->tab_list->previous;
	}
	ft_position_control(key, filler);
	ft_visualiser_launcher(filler);
	return (1);
}

int			main(void)
{
	t_filler *filler;

	if (!(ft_filler_init(&filler, 1)))
		return (1);
	if (!(ft_setup_init(&filler)))
		return (1);
	while (1)
	{
		if (!(ft_read_vm_out(filler)))
			break ;
		ft_filler_init(&filler, 0);
	}
	if (filler->tab_col == 0)
		ft_exit_management(filler);
	filler->scale = 800 / filler->tab_col;
	mlx_string_put(filler->setup->mlx_ptr, filler->setup->win_ptr,
			5, 810, 0xFF0000, "enemi");
	mlx_string_put(filler->setup->mlx_ptr, filler->setup->win_ptr,
			5, 830, 0x00FF00, "kdaou");
	if (filler->tab_list)
		ft_visualiser_launcher(filler);
	mlx_hook(filler->setup->win_ptr, 2, 0, ft_remote_filler, filler);
	mlx_loop(filler->setup->mlx_ptr);
	return (0);
}
