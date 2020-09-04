/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:15:58 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:47:57 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->win->bpp / 8) + (y * fractol->win->stride);
	fractol->win->img_data[i] = color.colors[fractol->blue];
	fractol->win->img_data[++i] = color.colors[fractol->green];
	fractol->win->img_data[++i] = color.colors[fractol->red];
	fractol->win->img_data[++i] = color.colors[0];
}

void	draw(t_fractol *fractol)
{
	int		x;
	int		y;
	t_color	color;

	y = fractol->start;
	while (y < fractol->finish)
	{
		x = 0;
		fractol->y = y;
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		while (x < WIDTH)
		{
			fractol->x = x;
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			ft_fractol(fractol);
			color = get_color(fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

void	cr_threads(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fract[THREADS];
	int			i;

	i = 0;
	fractol->factor = complex_create((fractol->max.re - fractol->min.re) /
			(WIDTH - 1), (fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	while (i < THREADS)
	{
		fract[i] = *fractol;
		fract[i].start = i * (HEIGHT / THREADS);
		fract[i].finish = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, (void *)draw, (void *)&fract[i]))
			print_err(ERR_TH);
		i++;
	}
	while (i > 0)
		if (pthread_join(threads[--i], NULL))
			print_err(ERR_TH);
	mlx_put_image_to_window(fractol->win->mlx_ptr,
			fractol->win->win_ptr, fractol->win->img, 0, 0);
	menu(fractol);
}
