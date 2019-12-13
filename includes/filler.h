/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:00:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/07/20 18:44:13 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "ft_mlx.h"
# include "libft.h"
# include <stdio.h>
# include "mathlibft.h"
# include <pthread.h>
# define RED 0xff0000
# define GREEN 0x00ff00

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_filler
{
	char		**tab;
	char		**piece;
	t_setup		*setup;
	char		player;
	char		enemi;
	int			tab_line;
	int			tab_col;
	int			piece_col;
	int			piece_line;
	int			isplaced;
	int			piece_size;
	int			minx;
	int			miny;
	int			score;
	t_point		out;
	int			scale;
	t_list		*tab_list;
	t_list		*piece_list;
	int			center;
}				t_filler;

int				ft_filler(t_filler *filler);
t_point			ft_new_point(int x, int y);
t_point			*ft_filler_piece(t_filler *filler);
int				ft_read_stdin(t_filler *filler);
int				ft_filler(t_filler *filler);
int				ft_filler_init(t_filler **filler, int verbos);
char			**ft_stock_table(int n, int plus);

void			ft_visualiser_launcher(t_filler *filler);
void			ft_draw_grid(t_filler *filler, int x, int y);
void			ft_fill_square(t_filler *filler, int x, int y, t_color color);
void			ft_fill_progression(t_setup *setup, int	x, int pos,
				t_color color);
int				ft_read_vm_out(t_filler *filler);
void			ft_exit_management(t_filler *filler);

#endif
