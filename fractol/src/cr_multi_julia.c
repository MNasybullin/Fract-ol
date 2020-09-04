/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_multi_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:02:26 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:35:09 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		cr_multi_julia(t_fractol *fractol)
{
	t_complex	z;
	int			iteration;
	double		n;

	iteration = 0;
	n = fractol->n;
	z = complex_create(fractol->c.re, fractol->c.im);
	while ((z.re * z.re) + (z.im * z.im) <= 4 &&
			iteration < fractol->max_iteration)
	{
		z = complex_create(pow((z.re * z.re) + (z.im * z.im), n / 2) *
				cos(n * atan2(z.im, z.re)) + fractol->k.re, pow((z.re * z.re) +
					(z.im * z.im), n / 2) * sin(n * atan2(z.im, z.re)) +
				fractol->k.im);
		iteration++;
	}
	return (iteration);
}
