/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:36:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/18 14:02:19 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		sl;
	int		end;
	int		color;
	double	x1;
	double	y1;
	double	zoom;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	int		arg;
	int		l;
	int		h;
	double	iter;
	int		stop;
	double	var_x;
	double	var_y;
	double	fact_in;
	double	fact_out;
	double	pal;
}				t_param;

# define WHITE 0xFFFFFF
# define GREEN 0x7df442
# define PURPLE 0xb52dff
# define RED 000000255

# define ESC 53
# define K1 18
# define K2 19
# define K3 20
# define K4 21
# define K5 23
# define PLUS 69
# define MINUS 78
# define KU 32
# define KL 37
# define ESP 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

void			generate(t_param *p);

void			draw_mandelbrot(t_param *p, const int x, const int y);

int				events_key(int kc, t_param *p);

int				events_mouse(int bc, int x, int y, t_param *p);

int				events_move(int x, int y, t_param *p);

void			draw_julia(t_param *p, const int x, const int y);

void			show_hud(t_param *p);

void			show_text(t_param *p);

void			draw_mandelbar(t_param *p, const int x, const int y);

void			reset_fract(t_param *p, int arg);

void			draw_burningship(t_param *p, int x, int y);

void			ft_colors(int kc, t_param *p);

void			mem_error(void);

#endif
