/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:16 by aaguiler          #+#    #+#             */
/*   Updated: 2022/06/15 11:29:19 by aaguiler         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		finalint;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str2[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str2[i] == '+')
		i++;
	finalint = 0;
	while (str2[i] >= '0' && str2[i] <= '9')
		finalint = finalint * 10 + (str2[i++] - '0');
	finalint *= sign;
	return (finalint);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

double	ft_atof(char *str)
{
	int		i;
	double	ret;
	double	n_deci;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ret = (double)ft_atoi(str);
		return (ret);
	}
	str[i] = '\0';
	ret = (double)ft_atoi(str);
	n_deci = (double)ft_atoi(&str[i + 1]);
	while (n_deci > 1)
		n_deci /= 10;
	while (str[++i] == '0')
		n_deci /= 10;
	if (str[0] == '-')
		return (ret - n_deci);
	return (ret + n_deci);
}
