/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:20 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/22 17:42:12 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	julia_iteration(double x, double y, t_fractol *fractol)
{
	t_fractol	z;
	int			i;
	double		temp_real;

	z.imag = y;
	z.real = x;
	i = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && i < 70)
	{
		temp_real = z.real * z.real - z.imag * z.imag + (fractol->first);
		z.imag = 2 * z.real * z.imag + (fractol->second);
		z.real = temp_real;
		i++;
	}
	return (i);
}

void	draw_julia_row(t_fractol *fractol, t_fractol *img, double i)
{
	double		j;
	t_fractol	f;
	int			itr;
	int			color;

	j = 0;
	while (j < fractol->widht)
	{
		f.real = get_x(j, fractol);
		f.imag = get_y(i, fractol);
		itr = julia_iteration(f.real, f.imag, fractol);
		color = get_color(itr);
		my_mlx_pixel_put(img, j, i, color);
		j++;
	}
}

int	julia(t_fractol *fractol)
{
	double		i;

	i = 0;
	fractol->img = mlx_new_image(fractol->mlx, fractol->widht, fractol->height);
	if (!fractol->img)
	{
		mlx_destroy_window(fractol->mlx, fractol->mlx_window);
		return (0);
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
	if (!fractol->addr)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_window);
		return (0);
	}
	while (i < fractol->height)
		(draw_julia_row(fractol, fractol, i), i++);
	mlx_put_image_to_window(fractol->mlx,
		fractol->mlx_window, fractol->img, 0, 0);
	return (1);
}
