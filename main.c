/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:39:59 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/18 13:49:47 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mem_error(void)
{
	ft_putstr_fd("memory error\n", 2);
	exit(0);
}

static int	check_fract2(char *str, t_param *p)
{
	if (ft_strcmp(str, "tricorn") == 0)
	{
		p->stop = 1;
		p->x1 = -2.8;
		p->y1 = -2.3;
		p->zoom = 150;
		p->iter = 40;
		p->var_x = 0;
		p->var_y = 0;
		return (3);
	}
	if (ft_strcmp(str, "burningship") == 0)
	{
		p->stop = 1;
		p->iter = 50;
		p->zoom = 165;
		p->x1 = -2.6;
		p->y1 = -3;
		p->var_x = 0;
		p->var_y = 0;
		return (4);
	}
	return (0);
}

static int	check_fract(char *str, t_param *p)
{
	p->fact_in = p->l * 0.0905;
	p->fact_out = p->l * 0.1;
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		p->stop = 1;
		p->x1 = -2.4;
		p->y1 = -1.7;
		p->zoom = 200;
		p->iter = 50;
		p->var_x = 0;
		p->var_y = 0;
		return (1);
	}
	if (ft_strcmp(str, "julia") == 0)
	{
		p->zoom = 200;
		p->x1 = -1.8;
		p->y1 = -1.7;
		p->iter = 50;
		p->c_r = 0.285;
		p->c_i = 0.01;
		return (2);
	}
	return (check_fract2(str, p));
}

static int	error_check(t_param *p, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(
			"usage : ./fractol [mandelbrot, julia, tricorn, burningship]\n", 2);
		return (-1);
	}
	if (!(p->arg = check_fract(argv[1], p)))
	{
		ft_putstr_fd(
			"wrong fractal name (mandelbrot, julia, tricorn, burningship)\n",
			2);
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_param p;

	p.l = 700;
	p.h = 700;
	p.pal = 1.5;
	if (error_check(&p, argc, argv) < 0)
		return (-1);
	p.mlx = mlx_init();
	p.ptr_img = mlx_new_image(p.mlx, p.l, p.h);
	p.img_str = mlx_get_data_addr(p.ptr_img, &(p.bpp), &(p.sl), &(p.end));
	p.win = mlx_new_window(p.mlx, p.l, p.h, "fractol");
	show_hud(&p);
	generate(&p);
	mlx_put_image_to_window(p.mlx, p.win, p.ptr_img, 0, 0);
	show_text(&p);
	mlx_hook(p.win, 2, 3, events_key, &p);
	mlx_mouse_hook(p.win, events_mouse, &p);
	mlx_hook(p.win, 6, 1L << 6, events_move, &p);
	mlx_loop(p.mlx);
	return (0);
}
