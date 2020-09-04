/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:33:12 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 14:49:44 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_color(t_fractol *fractol)
{
	if (fractol->red == 1 && fractol->green == 2 && fractol->blue == 3)
	{
		fractol->red = 1;
		fractol->green = 3;
		fractol->blue = 2;
	}
	else if (fractol->red == 1 && fractol->green == 3 && fractol->blue == 2)
	{
		fractol->red = 2;
		fractol->green = 1;
		fractol->blue = 3;
	}
	else if (fractol->red == 2 && fractol->green == 1 && fractol->blue == 3)
	{
		fractol->red = 3;
		fractol->green = 1;
		fractol->blue = 2;
	}
	else
		change_color2(fractol);
	cr_threads(fractol);
}

void	change_color2(t_fractol *fractol)
{
	if (fractol->red == 3 && fractol->green == 1 && fractol->blue == 2)
	{
		fractol->red = 2;
		fractol->green = 3;
		fractol->blue = 1;
	}
	else if (fractol->red == 2 && fractol->green == 3 && fractol->blue == 1)
	{
		fractol->red = 3;
		fractol->green = 2;
		fractol->blue = 1;
	}
	else if (fractol->red == 3 && fractol->green == 2 && fractol->blue == 1)
	{
		fractol->red = 1;
		fractol->green = 2;
		fractol->blue = 3;
	}
	cr_threads(fractol);
}

void	change_n(int key, t_fractol *fractol)
{
	if (key == 45)
		fractol->n = fractol->n + 1;
	else
		fractol->n = fractol->n - 1;
	cr_threads(fractol);
}

void	use_def(t_fractol *fractol)
{
	fr_default(fractol);
	cr_threads(fractol);
}

void	change_iteration(int key, t_fractol *fractol)
{
	if (key == 34)
		fractol->max_iteration += 10;
	if (key == 32 && fractol->max_iteration > 0)
		fractol->max_iteration -= 10;
	cr_threads(fractol);
}
