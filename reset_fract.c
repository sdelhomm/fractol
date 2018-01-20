/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:17:48 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/20 10:32:37 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_fract2(t_param *p)
{
	if (p->arg == 3)
	{
		p->stop = 1;
		p->x1 = -2.8;
		p->y1 = -2.3;
		p->zoom = 150;
		p->iter = 50;
		p->var_x = 0;
		p->var_y = 0;
	}
	if (p->arg == 4)
	{
		p->stop = 1;
		p->iter = 50;
		p->zoom = 165;
		p->x1 = -2.6;
		p->y1 = -3;
		p->var_x = 0;
		p->var_y = 0;
	}
}

void		reset_fract(t_param *p, int arg)
{
	p->arg = arg;
	if (p->arg == 1)
	{
		p->stop = 1;
		p->x1 = -2.4;
		p->y1 = -1.7;
		p->zoom = 200;
		p->iter = 50;
		p->var_x = 0;
		p->var_y = 0;
	}
	if (p->arg == 2)
	{
		p->zoom = 200;
		p->x1 = -1.8;
		p->y1 = -1.7;
		p->iter = 50;
		p->c_r = 0.285;
		p->c_i = 0.01;
	}
	reset_fract2(p);
}
