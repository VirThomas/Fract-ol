/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:53:26 by thabdoul          #+#    #+#             */
/*   Updated: 2017/08/18 14:08:05 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(int keycode, t_point *e)
{
	if (keycode == 69)
	{
		ft_bzero(e->img, (500 * 500) * 4);
		e->color += 1000;
		choose_fract(e);
		mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	}
	else if (keycode == 78)
	{
		ft_bzero(e->img, (500 * 500) * 4);
		e->color -= 1000;
		choose_fract(e);
		mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	check_arg(char *arg, t_point *e)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		mandelbrot(e);
	if (ft_strcmp(arg, "Mandelbrot2") == 0)
		mandelbrot2(e);
	if (ft_strcmp(arg, "Mandelbrot3") == 0)
		mandelbrot3(e);
	if (ft_strcmp(arg, "Julia") == 0)
		julia(e);
	if (ft_strcmp(arg, "Burn") == 0)
		burning(e);
	if (ft_strcmp(arg, "Tricorn") == 0)
		tricorn(e);
	if (ft_strcmp(arg, "Bat") == 0)
		bat(e);
	if (ft_strcmp(arg, "Celtic") == 0)
		celtic(e);
	else if (e->token != 1)
		list_args();
}

void	list_args(void)
{
	ft_putendl("\e[32m ---------------------");
	ft_putendl("|  \e[4mValid fractals:\e[24m    |");
	ft_putendl("|  -Mandelbrot        |");
	ft_putendl("|  -Mandelbrot2       |");
	ft_putendl("|  -Mandelbrot3       |");
	ft_putendl("|  -Julia             |");
	ft_putendl("|  -Burn              |");
	ft_putendl("|  -Tricorn           |");
	ft_putendl("|  -Bat               |");
	ft_putendl("|  -Celtic            |");
	ft_putendl(" ---------------------\e[0m");
	ft_putendl("\e[91m~ DON'T FORGET CAPS ~\e[0m");
	exit(0);
}

void	choose_fract(t_point *e)
{
	if (e->fract == 1)
		draw_mandel(e);
	if (e->fract == 2)
		draw_julia(e);
	if (e->fract == 3)
		draw_burning(e);
	if (e->fract == 4)
		draw_tricorn(e);
	if (e->fract == 5)
		draw_mandel2(e);
	if (e->fract == 6)
		draw_mandel3(e);
	if (e->fract == 7)
		draw_bat(e);
	if (e->fract == 8)
		draw_celtic(e);
}

int		move(int keycode, t_point *e)
{
	if (keycode == 1)
		e->y -= 0.1 / e->zoom;
	if (keycode == 13)
		e->y += 0.1 / e->zoom;
	if (keycode == 2)
		e->x -= 0.1 / e->zoom;
	if (keycode == 0)
		e->x += 0.1 / e->zoom;
	if (keycode == 71)
	{
		if (e->move == 0)
			e->move = 1;
		else
			e->move = 0;
		ft_putnbr(e->move);
	}
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21
			|| keycode == 22 || keycode == 23 || keycode == 26 || keycode == 28)
		change_reset(keycode, e);
	else
		choose_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	return (0);
}
