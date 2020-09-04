/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:33:20 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/12 18:18:37 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->k = complex_create(4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	cr_threads(fractol);
	return (0);
}

void	move_sier(int key, t_fractol *fractol)
{
	if (key == 123)
		fractol->rl = fractol->rl - 25;
	if (key == 124)
		fractol->rl = fractol->rl + 25;
	if (key == 126)
		fractol->ud = fractol->ud + 25;
	if (key == 125)
		fractol->ud = fractol->ud - 25;
}

void	help_menu(t_fractol *fractol)
{
	if (fractol->help == 0)
		fractol->help = 1;
	else if (fractol->help == 1)
		fractol->help = 0;
	cr_threads(fractol);
}
