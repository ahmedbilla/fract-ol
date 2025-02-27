/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:14:02 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/22 21:37:23 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom;

	x = x + 0;
	y = y + 0;
	if (button == ZOOM_IN)
		zoom = 0.9;
	else if (button == ZOOM_OUT)
		zoom = 1.1;
	else
		return (0);
	fractol->x_min *= zoom;
	fractol->x_max *= zoom;
	fractol->y_min *= zoom;
	fractol->y_max *= zoom;
	if (ft_strcmp(fractol->name, "mandelbrot\0") == 0)
		mandelbrot(fractol);
	else if (ft_strcmp(fractol->name, "julia") == 0)
		julia(fractol);
	return (0);
}

int	controler(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	mlx_mouse_hook(fractol->mlx_window, zoom, fractol);
	return (1);
}
