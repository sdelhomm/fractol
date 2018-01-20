/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:22:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/18 11:41:14 by sdelhomm         ###   ########.fr       */
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

static void	show_ui3(t_param *p)
{
	int x;
	int y;

	x = p->l * 0.78;
	while (x < (p->l * 0.97))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, RED);
			y++;
		}
		x++;
	}
}

static void	show_ui2(t_param *p)
{
	int x;
	int y;

	x = p->l * 0.28;
	while (x < (p->l * 0.47))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, RED);
			y++;
		}
		x++;
	}
	x = p->l * 0.53;
	while (x < (p->l * 0.72))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, RED);
			y++;
		}
		x++;
	}
}

static void	show_ui(t_param *p)
{
	int x;
	int y;

	x = p->l * 0.14;
	while (x < (p->l * 0.86))
	{
		y = p->h * 0.14;
		while (y < (p->h * 0.86))
		{
			fill_pixel(x, y, p, GREEN);
			y++;
		}
		x++;
	}
	x = p->l * 0.03;
	while (x < (p->l * 0.22))
	{
		y = p->h * 0.025;
		while (y < (p->h * 0.125))
		{
			fill_pixel(x, y, p, RED);
			y++;
		}
		x++;
	}
}

void		show_hud(t_param *p)
{
	show_ui(p);
	show_ui2(p);
	show_ui3(p);
}
