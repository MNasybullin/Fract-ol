/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:47:58 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 14:01:45 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractol(t_fractol *fractol)
{
	if (fractol->mandelbrot == 1)
		fractol->iteration = cr_mandelbrot(fractol);
	if (fractol->julia == 1)
		fractol->iteration = cr_julia(fractol);
	if (fractol->burning == 1)
		fractol->iteration = cr_burning(fractol);
	if (fractol->tricorn == 1)
		fractol->iteration = cr_tricorn(fractol);
	if (fractol->multibrot == 1)
		fractol->iteration = cr_multibrot(fractol);
	if (fractol->multi_julia == 1)
		fractol->iteration = cr_multi_julia(fractol);
	if (fractol->sierpinski == 1)
		fractol->iteration = cr_sierpinski(fractol);
}
