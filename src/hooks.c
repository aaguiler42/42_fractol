/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:38:26 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 14:01:32 by aaguiler         ###   ########.fr       */
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

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_var	*vars;
	t_pi	p;

	(void)xdelta;
	vars = (t_var *)param;
	p = (t_pi){xdelta, ydelta};
	if (ydelta > 0)
	{
		vars->middle = ft_pi_to_cn(vars, p);
		vars->range *= 0.5;
		vars->max_iters *= 1.05;
	}
	else if (ydelta < 0)
	{
		vars->middle = ft_pi_to_cn(vars, p);
		vars->range *= 1.5;
		vars->max_iters *= 0.95;
		if (vars->max_iters < 100)
			vars->max_iters = 100;
	}
	ft_print_fractals(vars);
	mlx_image_to_window(vars->mlx, vars->g_img, 0, 0);
}
