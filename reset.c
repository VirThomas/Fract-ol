/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:20:38 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 16:47:54 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_reset(int keycode, t_point *e)
{
	if (keycode == 18)
		mandelbrot(e);
	if (keycode == 19)
		mandelbrot2(e);
	if (keycode == 20)
		mandelbrot3(e);
	if (keycode == 21)
		julia(e);
	if (keycode == 22)
		burning(e);
	if (keycode == 23)
		tricorn(e);
	if (keycode == 26)
		bat(e);
	if (keycode == 28)
		celtic(e);
}
