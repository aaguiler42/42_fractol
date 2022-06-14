/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:47 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 19:07:47 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <stdio.h>

void	ft_print_fractals(t_var *vars)
{
	t_pi	pixel;
	t_cn	complex;
	int		iter;

	(void)pixel;
	(void)vars;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			complex = ft_pi_to_cn(vars, pixel);
			iter = vars->form(complex, vars->max_iters, vars->julia);
			mlx_put_pixel(vars->g_img, pixel.x, pixel.y, iter * vars->colors);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_image_to_window(vars->mlx, vars->g_img, 0, 0);
}

t_var	*ft_init_vars(void)
{
	t_var	*vars;

	vars = malloc(sizeof(t_var));
	if (!vars)
		return (0);
	vars->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!vars->mlx)
	{
		free(vars);
		exit(0);
	}
	vars->g_img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->max_iters = 100;
	vars->range = 2.5;
	vars->colors = 65468784;
	vars->mx = 0;
	vars->my = 0;
	return (vars);
}

void	ft_check_args(int argc, char **argv, t_var *vars)
{
	if (argc == 1 || (argv[1][0] != '1'
		&& argv[1][0] != '2' && argv[1][0] != '3'))
	{
		write(1, "1... Mandelbrot\n2... Julia\n3... Other(surprise)\n", 48);
		exit(0);
	}
	if (argv[1][0] == '1')
	{
		vars->middle = (t_cn){-1, 0};
		vars->form = mandelbrot;
	}
	else if (argv[1][0] == '3')
	{
		vars->middle = (t_cn){-1, 0};
		vars->form = burningship;
	}
	else if (argv[1][0] == '2')
	{
		vars->middle = (t_cn){0, 0};
		vars->form = julia;
		vars->julia = (t_cn){-0.4, 0.6};
		if (argc >= 4)
			vars->julia = (t_cn){ft_atof(argv[2]), ft_atof(argv[3])};
	}
}

int32_t	main(int argc, char **argv)
{
	t_var	*vars;

	vars = ft_init_vars();
	ft_check_args(argc, argv, vars);
	ft_print_fractals(vars);
	mlx_loop_hook(vars->mlx, &hook, vars->mlx);
	mlx_key_hook(vars->mlx, &my_keyhook, vars);
	mlx_cursor_hook(vars->mlx, &my_curhook, vars);
	mlx_scroll_hook(vars->mlx, &my_scrollhook, vars);
	mlx_loop(vars->mlx);
	return (0);
}
