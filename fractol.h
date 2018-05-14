/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:49:49 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/18 14:04:49 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z_init;
	double	z_tmp;
	int		max;
	int		i;
	double	zoom;
	double	zoom_y;
	double	zoom_x;
	double	image_x;
	double	image_y;
	char	*img;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	temp;
	void	*mlx;
	void	*win;
	void	*image;
	int		bpp;
	int		ed;
	int		sl;
	double	xb;
	double	xb2;
	double	yb;
	double	yb2;
	double	h;
	double	fcs;
	int		color;
	int		fract;
	int		move;
	int		xindex;
	int		yindex;
	double	scale;
	int		token;
	double	temp2;
	double	temp3;
}					t_point;

void				pixel_to_img(t_point *e, int color);
void				first_init(t_point *e);
void				init_graphics(t_point *e);
void				init_values(t_point *e);
void				init_values3(t_point *e);
void				init_values5(t_point *e);
void				init_values6(t_point *e);
void				init_values7(t_point *e);
void				init_values8(t_point *e);
void				init_valuesx(t_point *e);
void				init_valuesy(t_point *e);
void				draw_mandel(t_point *e);
void				draw_mandel2(t_point *e);
void				draw_mandel3(t_point *e);
void				draw_julia(t_point *e);
void				draw_burning(t_point *e);
void				draw_tricorn(t_point *e);
void				draw_bat(t_point *e);
void				draw_celtic(t_point *e);
void				mandelbrot(t_point *e);
void				mandelbrot2(t_point *e);
void				mandelbrot3(t_point *e);
void				julia(t_point *e);
void				burning(t_point *e);
void				tricorn(t_point *e);
void				bat(t_point *e);
void				celtic(t_point *e);
int					color(int keycode, t_point *e);
int					move(int keycode, t_point *e);
void				pixl_color(t_point *e);
void				choose_fract(t_point *e);
void				calc(t_point *e);
void				check_arg(char *arg, t_point *e);
void				list_args(void);
void				change_reset(int keycode, t_point *e);
int					exit_win(void);

#endif
