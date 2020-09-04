/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:51:22 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:30:44 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		cr_julia(t_fractol *fractol)
{
	t_complex	z;
	int			iteration;

	iteration = 0;
	z = complex_create(fractol->c.re, fractol->c.im);
	while ((z.re * z.re) + (z.im * z.im) <= 4 &&
			iteration < fractol->max_iteration)
	{
		z = complex_create((z.re * z.re) - (z.im * z.im) + fractol->k.re,
				2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}
