/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:20 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/08 21:36:46 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int julia_iteration(double x, double y, t_fractol *fractol)
{
    t_fractol z;
    z.imag = y;
    z.real = x;
    // printf("%f\n", fractol->first);
    
    int i = 0;
    while (z.real * z.real + z.imag * z.imag <= 4 && i < 70)
    {
        double temp_real = z.real * z.real - z.imag * z.imag + (fractol->first);
        z.imag = 2 * z.real * z.imag + (fractol->second);
        z.real = temp_real;
        i++;
    }
    return i;
}
int julia(t_fractol *fractol)
{

    double i = 0, j;
    t_fractol f;
    t_fractol img;
    int itr = 0;

    // if (fractol->x_min == 0 && fractol->x_max == 0)
    // {
    //     fractol->x_min = -2.0;
    //     fractol->x_max = 2.0;
    //     fractol->y_min = 2.0;
    //     fractol->y_max = -2.0;
    // }

    img.img = mlx_new_image(fractol->mlx, fractol->widht, fractol->height);

    
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    if (!img.addr)
    {
        return 0;
    }

    while (i < fractol->height)
    {
        j = 0;
        while (j < fractol->widht)
        {
   
            f.real = get_x(j, fractol);
            f.imag = get_y(i, fractol);
            itr = julia_iteration(f.real, f.imag, fractol);
            int color = get_color(itr);
            my_mlx_pixel_put(&img, j, i, color);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_window, img.img, 0, 0);
    return 1;
}