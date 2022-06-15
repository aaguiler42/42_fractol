/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:26 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/15 11:02:13 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		vars->colors *= 1.01;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		vars->middle.a += vars->range / 4;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		vars->middle.a -= vars->range / 4;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		vars->middle.b += vars->range / 4;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		vars->middle.b -= vars->range / 4;
	ft_print_fractals(vars);
	mlx_image_to_window(vars->mlx, vars->g_img, 0, 0);
}

void	my_curhook(double xpos, double ypos, void *param)
{
	t_var	*vars;

	vars = (t_var *)param;
	vars->mx = xpos;
	vars->my = ypos;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_var	*vars;
	t_cn	p2;

	(void)xdelta;
	vars = (t_var *)param;
	p2 = ft_pi_to_cn(vars, (t_pi){vars->mx, vars->my});
	if (ydelta < 0)
	{
		vars->middle = (t_cn){(vars->middle.a + p2.a) / 2,
			(vars->middle.b + p2.b) / 2};
		vars->range *= 0.5;
		vars->max_iters *= 1.05;
	}
	else if (ydelta > 0)
	{
		vars->middle = (t_cn){2 * vars->middle.a - p2.a,
			2 * vars->middle.b - p2.b};
		vars->range *= 2;
		vars->max_iters *= 0.95;
		if (vars->max_iters < 100)
			vars->max_iters = 100;
	}
	ft_print_fractals(vars);
	mlx_image_to_window(vars->mlx, vars->g_img, 0, 0);
}
