/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:14:59 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 16:39:42 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 720
# define WIDTH 720

# include "MLX42.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_cn
{
	double	a;
	double	b;
}	t_cn;

typedef struct s_pi
{
	int	x;
	int	y;
}	t_pi;

typedef struct s_var
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	double		max_iters;
	int			(*form)(t_cn, int);
	double		range;
	t_cn		middle;
	int			mx;
	int			my;
}	t_var;

// Hooks
void	hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void* param);
void	my_curhook(double xpos, double ypos, void *param);

//Utils
t_cn	ft_pi_to_cn(t_var *vars, t_pi pixel);
void	ft_print_fractals(t_var *vars);

//Fractals
int	mandelbrot(t_cn c, int max_iter);
int	burningship(t_cn c, int max_iter);

#endif