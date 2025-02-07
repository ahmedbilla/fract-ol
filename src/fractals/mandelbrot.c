/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:32:32 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/07 16:29:10 by ahbilla          ###   ########.fr       */
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

void my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
    char *dst;

 if (x >= 0 && x < data->widht && y >= 0 && y < data->height)
{
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

}
int mandelbrot(t_fractol *fractol)
{
    double i = 0, j;
    t_fractol f;
    t_fractol img;
    int itr = 0;

    if (fractol->x_min == 0 && fractol->x_max == 0)
    {
        fractol->x_min = -2.0;
        fractol->x_max = 2.0;
        fractol->y_min = 2.0;
        fractol->y_max = -2.0;
    }


    img.img = mlx_new_image(fractol->mlx, fractol->widht, fractol->height);
    if (!img.img)
    {
        printf("Error: mlx_new_image failed\n");
        return 0;
    }

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    if (!img.addr)
    {
        printf("Error: mlx_get_data_addr failed\n");
        return 0;
    }

    while (i < fractol->height)
    {
        j = 0;
        while (j < fractol->widht)
        {
            f.real = get_x(j, fractol);
            f.imag = get_y(i, fractol);
            itr = mandelbrot_iteration(&f);
            int color = get_color(itr);
            my_mlx_pixel_put(&img, j, i, color);
            j++;
        }
        i++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->mlx_window, img.img, 0, 0);
    return 1;
}
