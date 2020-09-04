/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_tricorn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:29:44 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:40:08 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		cr_tricorn(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = complex_create(fractol->c.re, fractol->c.im);
	while ((z.re * z.re) + (z.im * z.im) <= 4 &&
			iteration < fractol->max_iteration)
	{
		z = complex_create((z.re * z.re) - (z.im * z.im) +
				fractol->c.re, -2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
