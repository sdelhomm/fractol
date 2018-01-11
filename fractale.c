/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:40:09 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/02 16:42:43 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_pixel(int x, int y, t_param *p, int color)
{
	int i;

	i = (x * 4) + (y * p->sl);
	if (x < (p->sl / 4) && y < (p->sl / 4) && x > 0 && y > 0)
	{
		p->img_str[i + 2] = color % 1000;
		color = color / 1000;
		p->img_str[i + 1] = color % 1000;
		color = color / 1000;
		p->img_str[i] = color % 1000;
	}
}

void		draw_mandelbrot(t_param *p, const int x, const int y)
{
	double tmp;
	int i;

	p->c_r = (x / p->zoom + p->x1);
	p->c_i = (y / p->zoom + p->y1);
	p->z_r = p->varx;
	p->z_i = p->vary;
	i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && i < (int)p->iter)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * tmp + p->c_i;
		i++;
	}
	if (i == (int)p->iter)
		p->color = 000000000;
	else
		p->color = i*i*i;
	fill_pixel(x, y, p, p->color);
}

void		draw_julia(t_param *p, const int x, const int y)
{
	double tmp;
	int i;

	p->c_r = p->c_r;
	p->c_i = p->c_i;
	p->z_r = x / p->zoom + p->x1;
	p->z_i = y / p->zoom + p->y1;
	i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && i < (int)p->iter)
	{
		tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * tmp + p->c_i;
		i = i + 1;
	}
	if (i == (int)p->iter)
		p->color = 000000000;
	else
		p->color = i*i*i;
	fill_pixel(x, y, p, p->color);
}