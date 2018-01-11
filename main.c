/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:39:59 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/09 11:45:46 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		check_fract(char *str, t_param *p)
{
	p->factin = p->l * 0.0905;
	p->factout = p->l * 0.1;
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		p->stop = 1;
		p->x1 = -2.1;
		p->x2 = 0.6;
		p->y1 = -1.2;
		p->y2 = 1.2;
		p->zoom = 200;
		p->iter = 50;
		return (1);
	}
	if (ft_strcmp(str, "julia") == 0)
	{
		p->zoom = 200;
		p->x1 = -1.5;
		p->y1 = -1.6;
		p->iter = 100;
		p->c_r = 0.285;
		p->c_i = 0.01;
		return (2);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_param p;

	p.l = 700;
	p.h = 700;
	if (argc != 2)
	{
		ft_putstr("usage : ./fractol [mandelbrot, julia]\n");
		return (0);
	}
	if (!(p.arg = check_fract(argv[1], &p)))
	{
		ft_putstr("wrong fractal name (mandelbrot, julia)\n");
		return (0);
	}
	p.mlx = mlx_init();
	p.ptr_img = mlx_new_image(p.mlx, p.l, p.h);
	p.img_str = mlx_get_data_addr(p.ptr_img, &(p.bpp), &(p.sl), &(p.end));
	generate(&p);
	p.win = mlx_new_window(p.mlx, p.l, p.h, "fractol");
	mlx_put_image_to_window(p.mlx, p.win, p.ptr_img, 0, 0);
	mlx_hook(p.win, 2, 3, events_key, &p);
	mlx_mouse_hook(p.win, events_mouse, &p);
	mlx_hook(p.win, 6, 1L << 6, events_move, &p);
	mlx_loop(p.mlx);
	return (0);
}
