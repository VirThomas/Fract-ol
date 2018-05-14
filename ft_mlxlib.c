/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:35:48 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/16 14:26:38 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_to_img(t_point *e, int color)
{
	int		i;

	i = (4 * e->xindex) + (e->yindex * e->sl);
	if (e->xindex >= 0 && e->yindex >= 0
			&& e->xindex < e->sl / 4 && e->yindex < e->sl / 4)
	{
		e->img[i] = color;
		e->img[i + 1] = color >> 8;
		e->img[i + 2] = color >> 16;
	}
}

void	pixl_color(t_point *e)
{
	if (e->i == e->max)
		pixel_to_img(e, 0x000000);
	else
		pixel_to_img(e, e->i * e->color);
}
