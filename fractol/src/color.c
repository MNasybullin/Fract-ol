/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:56:50 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:27:04 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		get_color(t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)fractol->iteration / (double)fractol->max_iteration;
	color.colors[0] = 0;
	color.colors[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color.colors[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.colors[3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
