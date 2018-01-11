/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:40:13 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/09 11:04:12 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		events_mouse(int bc, int x, int y, t_param *p)
{
	double ScaleX;
	double ScaleY;

	ScaleY = (double)y / p->h;
	ScaleX = (double)x / p->l;
	p->factin = p->l * 0.0905;
	p->factout = p->l * 0.1;
	if (bc == 1 || bc == 4)
	{
		p->y1 = p->y1 + ((1 / (p->zoom / p->factin)) * ScaleY);
		p->x1 = p->x1 + ((1 / (p->zoom / p->factin)) * ScaleX);
		p->zoom = p->zoom * 1.1;
		p->iter += 0.25;
	}
	if (bc == 2 || bc == 5)
	{
		p->y1 = p->y1 - ((1 / (p->zoom / p->factout)) * ScaleY);
		p->x1 = p->x1 - ((1 / (p->zoom / p->factout)) * ScaleX);
		p->zoom = p->zoom / 1.1;
		p->iter -= 0.25;
	}
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	return (0);
}

int 	events_move(int x, int y, t_param *p)
{
	double ScaleX;
	double ScaleY;

	if (x < 0 || y < 0 || x > p->l || y > p->h || p->stop == 1)
		return (0);
	ScaleY = (double)y / p->h;
	ScaleX = (double)x / p->l;
	p->varx = ScaleX;
	p->vary = ScaleY - 0.5;
	p->c_r = ScaleX / 1 - 1;
	p->c_i = ScaleY / 1 - 1;
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	return (0);
}

int		reset_fract(t_param *p)
{
	if (p->arg == 1)
	{
		p->x1 = -2.1;
		p->x2 = 0.6;
		p->y1 = -1.2;
		p->y2 = 1.2;
		p->zoom = 400;
		p->iter = 50;
	}
	if (p->arg == 2)
	{
		p->zoom = 300;
		p->x1 = -1.8;
		p->y1 = -1.6;
		p->iter = 100;
		p->c_r = 0.285;
		p->c_i = 0.01;
	}
	return (0);
}

int		events_key(int kc, t_param *p)
{
	if (kc == 53)
		exit(0);
	if (kc == 126)
		p->y1 = p->y1 + (1 / (p->zoom / 10));
	if (kc == 123)
		p->x1 = p->x1 + (1 / (p->zoom / 10));
	if (kc == 124)
		p->x1 = p->x1 - (1 / (p->zoom / 10));
	if (kc == 125)
		p->y1 = p->y1 - (1 / (p->zoom / 10));
	if (kc == 69)
		p->iter++;
	if (kc == 78)
		p->iter--;
	if (kc == 37)
		p->stop = 1;
	if (kc == 32)
		p->stop = 0;
	if (kc == 49)
		reset_fract(p);
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	return (0);
}
