/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:40:13 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/20 12:48:11 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse2(int bc, int x, int y, t_param *p)
{
	double scale_x;
	double scale_y;

	scale_y = (double)y / (p->h * 0.85);
	scale_x = (double)x / (p->l * 0.85);
	p->fact_in = p->l * (0.09075 * 0.85);
	p->fact_out = p->l * (0.1 * 0.85);
	if (bc == 1 || bc == 4)
	{
		p->y1 = p->y1 + ((1 / (p->zoom / p->fact_in)) * scale_y);
		p->x1 = p->x1 + ((1 / (p->zoom / p->fact_in)) * scale_x);
		p->zoom = p->zoom * 1.1;
		p->iter += 0.2;
	}
	if (bc == 2 || bc == 5)
	{
		p->y1 = p->y1 - ((1 / (p->zoom / p->fact_out)) * scale_y);
		p->x1 = p->x1 - ((1 / (p->zoom / p->fact_out)) * scale_x);
		p->zoom = p->zoom / 1.1;
		p->iter -= 0.2;
	}
}

int			events_mouse(int bc, int x, int y, t_param *p)
{
	if ((x > p->l * 0.85 || y > p->h * 0.85 || x < p->l * 0.15
		|| y < p->l * 0.15) && bc == 1)
	{
		if (x > p->l * 0.03 && x < p->l * 0.22 && y > p->h * 0.025
			&& y < p->h * 0.125)
			reset_fract(p, 1);
		else if (x > p->l * 0.28 && x < p->l * 0.47 && y > p->h * 0.025
			&& y < p->h * 0.125)
			reset_fract(p, 2);
		else if (x > p->l * 0.53 && x < p->l * 0.72 && y > p->h * 0.025
			&& y < p->h * 0.125)
			reset_fract(p, 3);
		else if (x > p->l * 0.78 && x < p->l * 0.97 && y > p->h * 0.025
			&& y < p->h * 0.125)
			reset_fract(p, 4);
	}
	else if (!(x > p->l * 0.85 || y > p->h * 0.85 || x < p->l * 0.15
		|| y < p->l * 0.15))
		mouse2(bc, x, y, p);
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	show_text(p);
	return (0);
}

int			events_move(int x, int y, t_param *p)
{
	double scale_x;
	double scale_y;

	if (x > p->l * 0.85 || y > p->h * 0.85 || x < p->l * 0.15
		|| y < p->l * 0.15 || p->stop == 1)
		return (0);
	scale_y = (double)y / (p->h * 0.85);
	scale_x = (double)x / (p->l * 0.85);
	p->var_x = scale_x;
	p->var_y = scale_y - 0.5;
	p->c_r = (scale_x - 0.8) * 2;
	p->c_i = (scale_y - 0.8) * 2;
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	show_text(p);
	return (0);
}

int			events_key(int kc, t_param *p)
{
	if (kc == ESC)
		exit(0);
	if (kc == UP)
		p->y1 = p->y1 + (1 / (p->zoom / 10));
	if (kc == LEFT)
		p->x1 = p->x1 + (1 / (p->zoom / 10));
	if (kc == RIGHT)
		p->x1 = p->x1 - (1 / (p->zoom / 10));
	if (kc == DOWN)
		p->y1 = p->y1 - (1 / (p->zoom / 10));
	if (kc == PLUS)
		p->iter++;
	if (kc == MINUS)
		p->iter--;
	if (kc == KL)
		p->stop = 1;
	if (kc == KU)
		p->stop = 0;
	if (kc == ESP)
		reset_fract(p, p->arg);
	ft_colors(kc, p);
	generate(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	show_text(p);
	return (0);
}
