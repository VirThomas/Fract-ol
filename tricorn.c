/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:41:53 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:47:19 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values6(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->zoom = 1;
	e->zoom_x = 500 / e->z;
	e->zoom_y = 500 / e->z;
	e->max = 60;
	e->fract = 4;
	e->token = 1;
}

void	init_valuesy(t_point *e)
{
	e->x = -2;
	e->y = -1.35;
	e->z = 2.8;
	e->z_init = 2.8;
	e->zoom = 1;
	e->zoom_x = 500 / e->z;
	e->zoom_y = 500 / e->z;
	e->max = 60;
	e->fract = 8;
	e->token = 1;
}

void	draw_tricorn(t_point *e)
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
			while (e->i < e->max && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				e->temp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -(2 * e->z_i * e->temp) + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}

void	celtic(t_point *e)
{
	init_valuesy(e);
	draw_celtic(e);
}

void	draw_celtic(t_point *e)
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
			while (e->i < e->max && e->z_r * e->z_r + e->z_i * e->z_i < 4)
			{
				e->temp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r;
				e->z_i = e->z_i * e->temp * 2 + e->c_i;
				e->i++;
				pixl_color(e);
			}
			e->yindex++;
		}
		e->xindex++;
	}
}
