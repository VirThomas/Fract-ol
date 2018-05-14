/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:47:56 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:12:52 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "libft/libft.h"

void	init_values(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->image_x = 500;
	e->image_y = 500;
	e->max = 50;
	e->zoom = 1;
	e->zoom_x = e->image_x / e->z;
	e->zoom_y = e->image_y / e->z;
	e->fract = 1;
	e->token = 1;
}

void	init_values7(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->image_x = 500;
	e->image_y = 500;
	e->max = 50;
	e->zoom = 1;
	e->zoom_x = e->image_x / e->z;
	e->zoom_y = e->image_y / e->z;
	e->fract = 5;
	e->token = 1;
}

void	draw_mandel(t_point *e)
{
	e->xindex = 0;
	while (e->xindex < e->sl / 4)
	{
		e->yindex = 0;
		while (e->yindex < e->sl / 4)
		{
			e->c_r = e->xindex / e->zoom_x + e->x;
			e->c_i = e->yindex / e->zoom_y + e->y;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->temp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->temp + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}

void	draw_mandel2(t_point *e)
{
	e->xindex = 0;
	while (e->xindex < e->sl / 4)
	{
		e->yindex = 0;
		while (e->yindex < e->sl / 4)
		{
			e->c_r = e->xindex / e->zoom_x + e->x;
			e->c_i = e->yindex / e->zoom_y + e->y;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->temp = e->z_r;
				e->temp2 = e->z_r * e->z_r;
				e->temp3 = e->z_i * e->z_i;
				e->z_r = e->temp2 * e->z_r - 3 * e->z_r * e->temp3 + e->c_r;
				e->z_i = 3 * e->temp2 * e->z_i - e->temp3 * e->z_i + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}

void	draw_mandel3(t_point *e)
{
	e->xindex = 0;
	while (e->xindex < e->sl / 4)
	{
		e->yindex = 0;
		while (e->yindex < e->sl / 4)
		{
			calc(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->temp = e->z_r;
				e->temp2 = e->z_r * e->z_r;
				e->temp3 = e->z_i * e->z_i;
				e->z_r = e->temp2 * e->temp2 - 6 * e->temp2 * e->temp3
					+ e->temp3 * e->temp3 + e->c_r;
				e->z_i = 4 * e->temp2 * e->temp * e->z_i - 4 * e->temp *
					e->temp3 * e->z_i + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}
