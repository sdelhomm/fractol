/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:19:26 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/13 17:41:04 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_text(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 50, 40, 0xFFFFFF, "Mandelbrot");
	mlx_string_put(p->mlx, p->win, 325, 40, 0xFFFFFF, "Julia");
	mlx_string_put(p->mlx, p->win, 560, 40, 0xFFFFFF, "Tricorn");
	mlx_string_put(p->mlx, p->win, 640, 100, 0xFFFFFF, "S");
	mlx_string_put(p->mlx, p->win, 640, 120, 0xFFFFFF, "D");
	mlx_string_put(p->mlx, p->win, 640, 140, 0xFFFFFF, "E");
	mlx_string_put(p->mlx, p->win, 640, 160, 0xFFFFFF, "L");
	mlx_string_put(p->mlx, p->win, 640, 180, 0xFFFFFF, "H");
	mlx_string_put(p->mlx, p->win, 640, 200, 0xFFFFFF, "O");
	mlx_string_put(p->mlx, p->win, 640, 220, 0xFFFFFF, "M");
	mlx_string_put(p->mlx, p->win, 640, 240, 0xFFFFFF, "M");
	mlx_string_put(p->mlx, p->win, 640, 400, 0xFFFFFF, "@");
	mlx_string_put(p->mlx, p->win, 640, 420, 0xFFFFFF, "4");
	mlx_string_put(p->mlx, p->win, 640, 440, 0xFFFFFF, "2");
	mlx_string_put(p->mlx, p->win, 50, 200, 0xFFFFFF, "f");
	mlx_string_put(p->mlx, p->win, 50, 220, 0xFFFFFF, "r");
	mlx_string_put(p->mlx, p->win, 50, 240, 0xFFFFFF, "a");
	mlx_string_put(p->mlx, p->win, 50, 260, 0xFFFFFF, "c");
	mlx_string_put(p->mlx, p->win, 50, 280, 0xFFFFFF, "t");
	mlx_string_put(p->mlx, p->win, 50, 300, 0xFFFFFF, "o");
	mlx_string_put(p->mlx, p->win, 50, 320, 0xFFFFFF, "l");
}