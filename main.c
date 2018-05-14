/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:48:49 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/18 14:11:32 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, int x, int y, t_point *e)
{
	if (button > 0)
	{
		e->z_tmp = e->z;
		e->z = (e->z_init / e->zoom);
		e->x += (e->z_tmp - e->z) / 2;
		e->y += (e->z_tmp - e->z) / 2;
		e->scale = e->z / (e->sl / 4);
		x = x - (e->sl / 4) / 2;
		y = y - (e->sl / 4) / 2;
		e->x += (x * (e->z_tmp / (e->sl / 4))) - (x * e->scale);
		e->y += (y * (e->z_tmp / (e->sl / 4))) - (y * e->scale);
		e->zoom_x = (e->sl / 4) / e->z;
		e->zoom_y = (e->sl / 4) / e->z;
		choose_fract(e);
		mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	}
}

int		zoom_set(int button, int x, int y, t_point *e)
{
	if (button == 1 || button == 4)
	{
		e->zoom *= 1.1;
		if (e->max < 250)
			e->max += 1;
	}
	else if (button == 2 || button == 5)
	{
		e->zoom /= 1.1;
		if (e->max > 50)
			e->max -= 1;
	}
	zoom(button, x, y, e);
	return (0);
}

int		motion(int x, int y, t_point *e)
{
	if ((e->fract == 2 || e->fract == 7) && e->move == 1)
	{
		if (x >= 0 && x <= 250)
			e->c_i = ((double)x - 250) / 250;
		if (x <= 500 && x >= 250)
			e->c_i = ((double)x - 250) / 250;
		if (y >= 0 && y <= 250)
			e->c_r = -((double)y - 250) / 250;
		if (y <= 500 && y >= 250)
			e->c_r = -((double)y - 250) / 250;
		if (e->fract == 2)
			draw_julia(e);
		else if (e->fract == 7)
			draw_bat(e);
		mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	}
	return (0);
}

void	init_graphics(t_point *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 500, 500, "Fract'ol");
	e->image = mlx_new_image(e->mlx, 500, 500);
	e->img = mlx_get_data_addr(e->image, &e->bpp, &e->sl, &e->ed);
	e->move = 0;
}

int		main(int argc, char **argv)
{
	t_point		e;

	e.color = 1899750;
	if (argc != 2)
		exit(0);
	init_graphics(&e);
	check_arg(argv[1], &e);
	mlx_key_hook(e.win, move, &e);
	mlx_hook(e.win, 2, 0, color, &e);
	mlx_mouse_hook(e.win, zoom_set, &e);
	mlx_hook(e.win, 6, 7, motion, &e);
	mlx_hook(e.win, 17, 0, exit_win, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	mlx_loop(e.mlx);
}
