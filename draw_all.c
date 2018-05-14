/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:10:27 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:42:03 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_point *e)
{
	init_values(e);
	draw_mandel(e);
}

void	mandelbrot2(t_point *e)
{
	init_values7(e);
	draw_mandel2(e);
}

void	julia(t_point *e)
{
	init_values3(e);
	draw_julia(e);
}

void	burning(t_point *e)
{
	init_values5(e);
	draw_burning(e);
}

void	tricorn(t_point *e)
{
	init_values6(e);
	draw_tricorn(e);
}
