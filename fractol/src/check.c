/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:30:30 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 13:25:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2))
			return (0);
		else
			return (1);
	}
	return (0);
}

int		check_name(char *name, t_fractol *fractol)
{
	if (ft_strequ(name, "Mandelbrot") == 1)
		fractol->mandelbrot = 1;
	if (ft_strequ(name, "Julia") == 1)
		fractol->julia = 1;
	if (ft_strequ(name, "Burning") == 1)
		fractol->burning = 1;
	if (ft_strequ(name, "Tricorn") == 1)
		fractol->tricorn = 1;
	if (ft_strequ(name, "Multibrot") == 1)
		fractol->multibrot = 1;
	if (ft_strequ(name, "Multi_Julia") == 1)
		fractol->multi_julia = 1;
	if (ft_strequ(name, "Sierpinski") == 1)
		fractol->sierpinski = 1;
	if (fractol->mandelbrot == 1 || fractol->julia == 1 ||
			fractol->burning == 1 || fractol->tricorn == 1 ||
			fractol->multibrot == 1 || fractol->multi_julia == 1 ||
			fractol->sierpinski == 1)
		return (1);
	else
		return (0);
}

void	create(char *name)
{
	t_fractol	*fractol;
	t_win		*win;

	win = win_create();
	fractol = fr_create(win);
	if ((check_name(name, fractol)) == 0)
		use();
	cr_threads(fractol);
	mlx_hook(win->win_ptr, 2, 0, deal_key, fractol);
	mlx_hook(win->win_ptr, 4, 0, mouse_press, fractol);
	if (fractol->julia || fractol->multi_julia)
		mlx_hook(win->win_ptr, 6, 0, mouse_move, fractol);
	mlx_loop(win->mlx_ptr);
}
