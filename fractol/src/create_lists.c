/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:40:52 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 14:11:57 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*fr_create(t_win *win)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		print_err(FR_ERR);
	fractol->mandelbrot = 0;
	fractol->julia = 0;
	fractol->burning = 0;
	fractol->tricorn = 0;
	fractol->sierpinski = 0;
	fractol->multi_julia = 0;
	fractol->multibrot = 0;
	fractol->win = win;
	fr_default(fractol);
	return (fractol);
}

t_win		*win_create(void)
{
	t_win		*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		print_err(WIN_CR);
	if (!(win->mlx_ptr = mlx_init()))
		print_err(WIN_CR);
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH,
					HEIGHT, "Fractol")))
		print_err(WIN_CR);
	if (!(win->img = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT)))
		print_err(WIN_CR);
	if (!(win->img_data = mlx_get_data_addr(win->img, &win->bpp,
					&win->stride, &win->endian)))
		print_err(WIN_CR);
	return (win);
}

t_complex	complex_create(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		fr_default(t_fractol *fractol)
{
	fractol->min = complex_create(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) *
		HEIGHT / WIDTH;
	fractol->k = complex_create(-0.4, 0.6);
	fractol->max_iteration = 50;
	fractol->change_color = 0;
	fractol->iteration = 0;
	fractol->rl = 0;
	fractol->ud = 0;
	fractol->red = 1;
	fractol->green = 2;
	fractol->blue = 3;
	fractol->x = 0;
	fractol->y = 0;
	fractol->n = 3;
	fractol->help = 0;
}
