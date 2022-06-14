/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:16 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/14 16:59:18 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cn	ft_pi_to_cn(t_var *vars, t_pi pixel)
{
	t_cn	c;

	c.a = vars->middle.a + 2 * vars->range * (pixel.x / (double)WIDTH - 0.5);
	c.b = vars->middle.b + 2 * vars->range * (pixel.y / (double)HEIGHT - 0.5);
	return (c);
}
