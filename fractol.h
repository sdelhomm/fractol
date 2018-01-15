/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:36:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/15 14:18:16 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"

# define ABS(Value) (Value < 0 ? -Value : Value)

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
	int		color1;
	int		color2;
	double	tmp;
	int		ox;
	int		oy;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	zoom;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	int		arg;
	int 	l;
	int		h;
	double	iter;
	int		stop;
	double	varx;
	double	vary;
	double	factin;
	double	factout;
}				t_param;

# define WHITE 255255255
# define BLACK 000000000
# define LBLUE 000255255
# define DBLUE 165140025
# define LGREEN 100050200
# define DGREEN 000255000
# define YELLOW 100255050
# define PURPLE 000000255
# define LRED 250090000
# define DRED 255000255
# define ORANGE 200030100
# define PINK 010200050
# define BROWN 000050150

# define ESC 53
# define K1 18
# define K2 20
# define K3 21
# define K4 23
# define K5 19
# define PLUS 69
# define MINUS 78
# define KI 34
# define KO 31
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define ESP 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

void			generate(t_param *p);

void			draw_mandelbrot(t_param *p, const int x, const int y);

int				events_key(int kc, t_param *p);

int				events_mouse(int bc, int x, int y, t_param *p);

int 			events_move(int x, int y, t_param *p);

void			draw_julia(t_param *p, const int x, const int y);

void			show_hud(t_param *p);

void			show_text(t_param *p);

void			draw_mandelbar(t_param *p, const int x, const int y);

void			reset_fract(t_param *p);

#endif
