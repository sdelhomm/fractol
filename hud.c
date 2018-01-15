/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:22:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/13 17:38:59 by sdelhomm         ###   ########.fr       */
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

void	show_hud(t_param *p)
{
	int x;
	int y;

	x = p->l * 0.14;
	while (x < (p->l * 0.86))
	{
		y = p->h * 0.14;
		while (y < (p->h * 0.86))
		{
			fill_pixel(x, y, p, ORANGE);
			y++;
		}
		x++;
	}
	x = p->l * 0.05;
	while (x < (p->l * 0.25))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, DBLUE);
			y++;
		}
		x++;
	}
	x = p->l * 0.4;
	while (x < (p->l * 0.6))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, DBLUE);
			y++;
		}
		x++;
	}
	x = p->l * 0.75;
	while (x < (p->l * 0.95))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, DBLUE);
			y++;
		}
		x++;
	}
}