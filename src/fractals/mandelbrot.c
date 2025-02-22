/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:32:32 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/08 22:15:59 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mandelbrot_iteration(t_fractol *fractol)
{
	t_fractol	z;
	int			i;
	double		temp_real;

	z.imag = 0;
	z.real = 0;
	i = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && i < 70)
	{
		temp_real = z.real * z.real - z.imag * z.imag + fractol->real;
		z.imag = 2 * z.real * z.imag + fractol->imag;
		z.real = temp_real;
		i++;
	}
	return (i);
}

void	draw_mandelbrot_row(t_fractol *fractol, t_fractol *img, double i)
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
		itr = mandelbrot_iteration(&f);
		color = get_color(itr);
		my_mlx_pixel_put(img, j, i, color);
		j++;
	}
}

int	mandelbrot(t_fractol *fractol)
{
	double		i;

	i = 0;
	fractol->img = mlx_new_image(fractol->mlx, fractol->widht, fractol->height);
	if (!fractol->img)
		mlx_destroy_window(fractol->mlx, fractol->mlx_window);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
	if (!fractol->addr)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_window);
	}
	while (i < fractol->height)
	{
		draw_mandelbrot_row(fractol, fractol, i);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx,
		fractol->mlx_window, fractol->img, 0, 0);
	return (1);
}
