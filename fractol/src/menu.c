/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:37:22 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/12 18:20:58 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	menu(t_fractol *fractol)
{
	t_win	*mlx;
	t_win	*wind;

	mlx = fractol->win->mlx_ptr;
	wind = fractol->win->win_ptr;
	if (fractol->help == 1)
		menu1(fractol);
	if (fractol->help == 0)
	{
		mlx_string_put(mlx, wind, WIDTH - 135, HEIGHT - 25,
				0x636363, "H - Help menu");
	}
}

void	menu1(t_fractol *fractol)
{
	t_win	*mlx;
	t_win	*wind;

	mlx = fractol->win->mlx_ptr;
	wind = fractol->win->win_ptr;
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 25,
			0x636363, "Zoom : Scroll mouse");
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 45,
			0x636363, "Move : <- | -> ...");
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 65,
			0x636363, "Color : C");
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 85,
			0x636363, "Iteration : U | I");
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 105,
			0x636363, "Default : D");
	mlx_string_put(mlx, wind, WIDTH - 195, HEIGHT - 125,
			0x636363, "Variation : N | M");
}
