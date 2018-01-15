/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:40:13 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/15 14:19:42 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse2(int bc, int x, int y, t_param *p)
{
	double ScaleX;
	double ScaleY;

	if (x > p->l * 0.85 || y > p->h * 0.85 || x < p->l * 0.15 || y < p->l * 0.15)
		return ;
	ScaleY = (double)y / (p->h * 0.85);
	ScaleX = (double)x / (p->l * 0.85);
	p->factin = p->l * (0.0909 * 0.85);
	p->factout = p->l * (0.1 * 0.85);
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
}

int		events_mouse(int bc, int x, int y, t_param *p)
{
	if (x > p->l * 0.05 && x < p->l * 0.25 && y > p->h * 0.025 && y < p->h * 0.125 && bc == 1)
	{
		p->arg = 1;
		reset_fract(p);
	}
	else if (x > p->l * 0.4 && x < p->l * 0.6 && y > p->h * 0.025 && y < p->h * 0.125 && bc == 1)
	{
		p->arg = 2;
		reset_fract(p);
	}
	else if (x > p->l * 0.75 && x < p->l * 0.95 && y > p->h * 0.025 && y < p->h * 0.125 && bc == 1)
	{
		p->arg = 3;
		reset_fract(p);
	}
	else
		mouse2(bc, x, y, p);
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	show_text(p);
	return (0);
}

int 	events_move(int x, int y, t_param *p)
{
	double ScaleX;
	double ScaleY;

	if (x > p->l * 0.85 || y > p->h * 0.85 || x < p->l * 0.15 || y < p->l * 0.15 || p->stop == 1)
		return (0);
	ScaleY = (double)y / p->h;
	ScaleX = (double)x / p->l;
	p->varx = ScaleX;
	p->vary = ScaleY - 0.5;
	p->c_r = ScaleX / 1 - 1;
	p->c_i = ScaleY / 1 - 1;
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	show_text(p);
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
	show_text(p);
	return (0);
}
