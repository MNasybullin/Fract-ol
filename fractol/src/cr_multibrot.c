/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_multibrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:02:50 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:36:34 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		cr_multibrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;
	double		n;

	n = fractol->n;
	iteration = 0;
	z = complex_create(fractol->c.re, fractol->c.im);
	while ((z.re * z.re) + (z.im * z.im) <= 4 &&
			iteration < fractol->max_iteration)
	{
		z = complex_create(pow((z.re * z.re) + (z.im * z.im), n / 2) *
				cos(n * atan2(z.im, z.re)) + fractol->c.re, pow((z.re * z.re) +
					(z.im * z.im), n / 2) * sin(n * atan2(z.im, z.re)) +
				fractol->c.im);
		iteration++;
	}
	return (iteration);
}
