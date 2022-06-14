/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:26 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 18:05:32 by aaguiler         ###   ########.fr       */
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
	t_pi	p;
	t_cn	p2;

	vars = (t_var *)param;
	p = (t_pi){vars->mx, vars->my};
	p2 = ft_pi_to_cn(vars, p);
	if (ydelta + xdelta - xdelta < 0)
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
