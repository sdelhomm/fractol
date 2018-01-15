/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:40:03 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/15 11:42:40 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate(t_param *p)
{
	intmax_t x;
	intmax_t y;

	x = p->l * 0.15;
	while (x < (p->l * 0.85))
	{
		y = p->h * 0.15;
		while (y < (p->h * 0.85))
		{
			if (p->arg == 1)
				draw_mandelbrot(p, x, y);
			if (p->arg == 2)
				draw_julia(p, x, y);
			if (p->arg == 3)
				draw_mandelbar(p, x, y);
			y++;
		}
		x++;
	}
}
