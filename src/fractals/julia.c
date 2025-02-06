/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:20 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/06 17:19:24 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int mandelbroat(t_fractol *fractol)
{
    t_fractol z;
    z.imag = 0;
    z.real = 0;
    int i = 0;
    while (z.real * z.real + z.imag * z.imag <= 4 && i < 70)
    {
        // z.real = (z.real * z.real) - (z.imag * z.imag) + fractol->real;
        // z.imag = 2 * z.real * z.imag + fractol->imag;

        double temp_real = z.real * z.real - z.imag * z.imag + fractol->real;
        z.imag = 2 * z.real * z.imag + fractol->imag;
        z.real = temp_real;

        i++;
    }
    return i;
}
double get_x(double j)
{
    return (-2.0 + (j / 800.00) * (1.0 - (-2.0)));
}
double get_y(double i)
{
    return (1.5 + (i / 800.00) * (-1.5 - (1.5)));
}
int get_color(int x)
{
    if (x == 70)
        return (0);
    else
        return ((x * 255) / 70) << 10;
}
// void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
// {
// 	char	*dst;
//         if (!data || !data->addr || x < 0 || x >= 800 || y < 0 || y >= 800)
//         return;
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
int julia(t_fractol *fractol)
{
    double i = 0;
    double j;
    t_fractol f;
    int itr = 0;

    while (i < 800)
    {
        j = 0;
        while (j < 800)
        {
            f.real = get_x(i);
            f.imag = get_y(j);
            itr = mandelbroat(&f);
            int color = get_color(itr);
            // my_mlx_pixel_put(fractol, i, j, color);
            mlx_pixel_put(fractol->mlx, fractol->mlx_window, i, j, color);
            j++;
        }
        i++;
    }
    return 1;
}