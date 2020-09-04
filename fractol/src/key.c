/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:57:26 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 14:53:19 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_img2(int key, t_fractol *fractol, t_complex delta)
{
	if (key == 126)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	if (key == 125)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	cr_threads(fractol);
}

void	move_img(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = complex_create(fabs(fractol->max.re - fractol->min.re),
			fabs(fractol->max.im - fractol->min.im));
	if (fractol->sierpinski)
		move_sier(key, fractol);
	if (key == 123)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	if (key == 124)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	move_img2(key, fractol, delta);
}

int		deal_key(int key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key == 123 || key == 124 || key == 126 || key == 125)
		move_img(key, fractol);
	if (key == 53)
		exit(0);
	if (key == 45 || key == 46)
		change_n(key, fractol);
	if (key == 8)
		change_color(fractol);
	if (key == 2)
		use_def(fractol);
	if (key == 34 || key == 32)
		change_iteration(key, fractol);
	if (key == 4)
		help_menu(fractol);
	return (0);
}

void	zoom(int key, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		zoom;

	mouse = complex_create((double)x / (WIDTH / (fractol->max.re -
					fractol->min.re)) + fractol->min.re, (double)y /
			(HEIGHT / (fractol->max.im - fractol->min.im)) *
			-1 + fractol->max.im);
	if (key == 5)
		zoom = 0.75;
	else
		zoom = 1.25;
	fractol->min.re = mouse.re + ((fractol->min.re - mouse.re) * zoom);
	fractol->min.im = mouse.im + ((fractol->min.im - mouse.im) * zoom);
	fractol->max.re = mouse.re + ((fractol->max.re - mouse.re) * zoom);
	fractol->max.im = mouse.im + ((fractol->max.im - mouse.im) * zoom);
	cr_threads(fractol);
}

int		mouse_press(int key, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key == 4 || key == 5)
		zoom(key, x, y, fractol);
	return (0);
}
