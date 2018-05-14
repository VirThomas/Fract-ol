/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:53:16 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:41:58 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values8(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->max = 50;
	e->zoom = 1;
	e->zoom_x = 500 / e->z;
	e->zoom_y = 500 / e->z;
	e->fract = 6;
	e->token = 1;
}

void	mandelbrot3(t_point *e)
{
	init_values8(e);
	draw_mandel3(e);
}

void	calc(t_point *e)
{
	e->c_r = e->xindex / e->zoom_x + e->x;
	e->c_i = e->yindex / e->zoom_y + e->y;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
}

void	bat(t_point *e)
{
	init_valuesx(e);
	draw_bat(e);
}

int		exit_win(void)
{
	exit(0);
}
