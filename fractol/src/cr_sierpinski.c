/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_sierpinski.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:32:31 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:38:33 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		cr_sierpinski(t_fractol *fractol)
{
	int	x;
	int	y;
	int	n;
	int	iteration;

	iteration = 0;
	n = fractol->n;
	x = fractol->x + fractol->rl;
	y = fractol->y + fractol->ud;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (iteration * n);
		x /= 3;
		y /= 3;
		iteration++;
	}
	return (iteration * n);
}
