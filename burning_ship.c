/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:51:18 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:47:05 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values5(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->image_x = 500;
	e->image_y = 500;
	e->zoom = 1;
	e->zoom_x = e->image_x / e->z;
	e->zoom_y = e->image_y / e->z;
	e->max = 90;
	e->fract = 3;
	e->token = 1;
}

void	draw_burning(t_point *e)
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
				e->z_i = 2 * fabs(e->z_i * e->temp) + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}
