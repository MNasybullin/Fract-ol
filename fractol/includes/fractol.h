/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:46:07 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/11 14:15:25 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH  	800
# define HEIGHT 	800
# define THREADS	16
# include "errors.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>

typedef	struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef	struct		s_color
{
	int				colors[4];
}					t_color;

typedef	struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*img_data;
	void			*img;
	int				bpp;
	int				stride;
	int				endian;
}					t_win;

typedef struct		s_fractol
{
	int				mandelbrot;
	int				julia;
	int				burning;
	int				tricorn;
	int				multibrot;
	int				multi_julia;
	int				sierpinski;
	int				x;
	int				y;
	int				rl;
	int				ud;
	int				start;
	int				finish;
	t_complex		c;
	double			n;
	t_complex		k;
	t_complex		j;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	int				max_iteration;
	int				change_color;
	int				iteration;
	int				red;
	int				green;
	int				blue;
	int				help;
	t_win			*win;
}					t_fractol;

void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				print_err(char *s);
void				use(void);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				create(char *name);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					check_name(char *name, t_fractol *fractol);
t_fractol			*fr_create(t_win *win);
t_win				*win_create(void);
void				fr_default(t_fractol *fractol);
t_color				get_color(t_fractol *fractol);
void				ft_fractol(t_fractol *fractol);
int					cr_mandelbrot(t_fractol *fractol);
void				draw(t_fractol *fractol);
void				put_pixel(t_fractol *fractol, int x, int y, t_color color);
t_complex			complex_create(double re, double im);
int					cr_julia(t_fractol *fractol);
int					cr_burning(t_fractol *fractol);
int					cr_tricorn(t_fractol *fractol);
int					cr_multibrot(t_fractol *fractol);
int					cr_multi_julia(t_fractol *fractol);
int					cr_sierpinski(t_fractol *fractol);
int					deal_key(int key, void *param);
void				move_img(int key, t_fractol *fractol);
int					mouse_press(int key, int x, int y, void *param);
void				zoom(int key, int x, int y, t_fractol *fractol);
void				cr_threads(t_fractol *fractol);
void				move_sier(int key, t_fractol *fractol);
void				change_n(int key, t_fractol *fractol);
void				change_color(t_fractol *fractol);
void				change_color2(t_fractol *fractol);
void				use_def(t_fractol *fractol);
int					mouse_move(int x, int y, void *param);
void				change_iteration(int key, t_fractol *fractol);
void				move_img2(int key, t_fractol *fractol, t_complex delta);
void				menu(t_fractol *fractol);
void				menu1(t_fractol *fractol);
void				help_menu(t_fractol *fractol);

#endif
