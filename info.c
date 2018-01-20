/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:19:26 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/18 13:38:42 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	show_command(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 75, 630, GREEN, "Arrows to move");
	mlx_string_put(p->mlx, p->win, 75, 650, GREEN, "Space to reset");
	mlx_string_put(p->mlx, p->win, 335, 630, GREEN,
		"Mouse wheel or click to zoom in/out");
	mlx_string_put(p->mlx, p->win, 75, 670, GREEN, "+/- for deepness");
	mlx_string_put(p->mlx, p->win, 335, 660, GREEN,
		"U/L to unlock lock the variation");
}

static void	show_text2(t_param *p)
{
	char *deep;
	char *tmp;

	tmp = ft_itoa(p->iter);
	if (!(deep = (char*)malloc((7 + ft_strlen(tmp)) * sizeof(*deep))))
		mem_error();
	ft_strbuild(&deep, "Deep = ", tmp);
	mlx_string_put(p->mlx, p->win, 50, 220, WHITE, "f");
	mlx_string_put(p->mlx, p->win, 50, 240, WHITE, "r");
	mlx_string_put(p->mlx, p->win, 50, 260, WHITE, "a");
	mlx_string_put(p->mlx, p->win, 50, 280, WHITE, "c");
	mlx_string_put(p->mlx, p->win, 50, 300, WHITE, "t");
	mlx_string_put(p->mlx, p->win, 50, 320, WHITE, "o");
	mlx_string_put(p->mlx, p->win, 50, 340, WHITE, "l");
	mlx_string_put(p->mlx, p->win, 75, 610, GREEN, deep);
	free(tmp);
	free(deep);
}

void		show_text(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 0.0528 * p->l, 0.0571 * p->h,
		WHITE, "Mandelbrot");
	mlx_string_put(p->mlx, p->win, 0.3357 * p->l, 0.0571 * p->h,
		WHITE, "Julia");
	mlx_string_put(p->mlx, p->win, 0.5755 * p->l, 0.0571 * p->h,
		WHITE, "Tricorn");
	mlx_string_put(p->mlx, p->win, 0.8 * p->l, 0.0571 * p->h,
		WHITE, "Burningship");
	mlx_string_put(p->mlx, p->win, 640, 120, WHITE, "S");
	mlx_string_put(p->mlx, p->win, 640, 140, WHITE, "D");
	mlx_string_put(p->mlx, p->win, 640, 160, WHITE, "E");
	mlx_string_put(p->mlx, p->win, 640, 180, WHITE, "L");
	mlx_string_put(p->mlx, p->win, 640, 200, WHITE, "H");
	mlx_string_put(p->mlx, p->win, 640, 220, WHITE, "O");
	mlx_string_put(p->mlx, p->win, 640, 240, WHITE, "M");
	mlx_string_put(p->mlx, p->win, 640, 260, WHITE, "M");
	mlx_string_put(p->mlx, p->win, 640, 400, WHITE, "@");
	mlx_string_put(p->mlx, p->win, 640, 420, WHITE, "4");
	mlx_string_put(p->mlx, p->win, 640, 440, WHITE, "2");
	show_text2(p);
	show_command(p);
}
