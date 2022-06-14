/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:18:44 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 18:03:17 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_cn c, int max_iter, t_cn args)
{
	t_cn		z;
	t_cn		z2;
	int			i;

	(void)args;
	z.a = 0;
	z.b = 0;
	z2.a = 0;
	z2.b = 0;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		z.b = 2 * z.a * z.b + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	julia(t_cn z, int max_iter, t_cn args)
{
	t_cn	z2;
	int		i;
	t_cn	c;

	z2.a = z.a * z.a;
	z2.b = z.b * z.b;
	c = args;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		z.b = 2 * z.a * z.b + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	burningship(t_cn c, int max_iter, t_cn args)
{
	t_cn	z;
	t_cn	z2;
	int		i;
	double	prod;

	(void)args;
	z.a = 0;
	z.b = 0;
	z2.a = 0;
	z2.b = 0;
	i = 0;
	while (i < max_iter && z2.a + z2.b < 4)
	{
		prod = z.a * z.b;
		if (prod < 0)
			prod = -prod;
		z.b = 2 * prod + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}
