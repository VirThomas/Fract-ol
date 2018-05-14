/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:43:07 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:35:39 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values3(t_point *e)
{
	e->x = -1.2;
	e->y = -1.1;
	e->z = 2.2;
	e->z_init = 2.2;
	e->max = 50;
	e->zoom = 1;
	e->image_x = 500;
	e->image_y = 500;
	e->zoom_x = e->image_x / e->z;
	e->zoom_y = e->image_y / e->z;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->token = 1;
	e->fract = 2;
}

void	init_valuesx(t_point *e)
{
	e->x = -1.2;
	e->y = -1.1;
	e->z = 2.2;
	e->z_init = 2.2;
	e->max = 50;
	e->zoom = 1;
	e->image_x = 500;
	e->image_y = 500;
	e->zoom_x = e->image_x / e->z;
	e->zoom_y = e->image_y / e->z;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->token = 1;
	e->fract = 7;
}

void	draw_julia(t_point *e)
{
	e->xindex = 0;
	while (e->xindex < e->image_x)
	{
		e->yindex = 0;
		while (e->yindex < e->image_y)
		{
			e->z_r = e->xindex / e->zoom_x + e->x;
			e->z_i = e->yindex / e->zoom_y + e->y;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->temp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->temp + e->c_i;
				e->i++;
				if (e->i == e->max)
					pixel_to_img(e, 0xFFFFFF);
				else
					pixel_to_img(e, e->i * e->color);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}

void	draw_bat(t_point *e)
{
	e->xindex = 0;
	while (e->xindex < e->image_x)
	{
		e->yindex = 0;
		while (e->yindex < e->image_y)
		{
			e->z_r = e->xindex / e->zoom_x + e->x;
			e->z_i = e->yindex / e->zoom_y + e->y;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->temp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->temp + e->c_i * e->z_i;
				e->i++;
				if (e->i == e->max)
					pixel_to_img(e, 0x000000);
				else
					pixel_to_img(e, e->i * e->color);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}
