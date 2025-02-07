/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:32:32 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/07 15:14:33 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int mandelbrot_iteration(t_fractol *fractol)
{
    t_fractol z;
    z.imag = 0;
    z.real = 0;
    int i = 0;
    while (z.real * z.real + z.imag * z.imag <= 4 && i < 70)
    {
        double temp_real = z.real * z.real - z.imag * z.imag + fractol->real;
        z.imag = 2 * z.real * z.imag + fractol->imag;
        z.real = temp_real;
        i++;
    }
    return i;
}
double get_x(double j, t_fractol *fractol)
{
    return (fractol->x_min + (j / 800.00) * (fractol->x_max - fractol->x_min));
}

double get_y(double i, t_fractol *fractol)
{
    return (fractol->y_max - (i / 800.00) * (fractol->y_max - fractol->y_min));
}
int get_color(int x)
{
    if (x == 70)
        return (0);
    else
        return ((x * 255) / 70) << 10;
}
int mandelbrot(t_fractol *fractol)
{

    double i = 0;
    double j;
    t_fractol f;
    int itr = 0;
    
 if (fractol->x_min == 0 && fractol->x_max == 0)
    {
        fractol->x_min = -2.0;
        fractol->x_max = 1.0;
        fractol->y_min = -1.5;
        fractol->y_max = 1.5;
    }

        printf("Before Zoom: x_min = %lf, x_max = %lf, y_min = %lf, y_max = %lf\n",
           fractol->x_min, fractol->x_max, fractol->y_min, fractol->y_max);

    while (i < 800)
    {
        j = 0;
        while (j < 800)
        {
            f.real = get_x(i, fractol);
            f.imag = get_y(j, fractol);
            itr = mandelbrot_iteration(&f);
            int color = get_color(itr);
            mlx_pixel_put(fractol->mlx, fractol->mlx_window, i, j, color);
            j++;
        }
        i++;
    }
    return 1;
}