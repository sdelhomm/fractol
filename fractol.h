/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:36:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/09 11:02:19 by sdelhomm         ###   ########.fr       */
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

void			generate(t_param *p);

void			draw_mandelbrot(t_param *p, const int x, const int y);

int				events_key(int kc, t_param *p);

int				events_mouse(int bc, int x, int y, t_param *p);

int 			events_move(int x, int y, t_param *p);

void			draw_julia(t_param *p, const int x, const int y);

#endif
