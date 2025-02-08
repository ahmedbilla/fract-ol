/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student->42->fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:19:31 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/25 22:26:55 by ahbilla          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int create_window(t_fractol *fractol, char *av[])
{
    fractol->widht = 800;
    fractol->height = 800;
    fractol->mlx = mlx_init();
    fractol->mlx_window = mlx_new_window(fractol->mlx, fractol->widht, fractol->height, *av);
    if (!fractol->mlx_window)
        return 1;
    mlx_key_hook(fractol->mlx_window, &close_window, NULL);
    mlx_hook(fractol->mlx_window, 17, 0, &close_cross, fractol);
    if (ft_strcmp(*av, "mandelbrot") == 0)
        mandelbrot(fractol);
    else if (ft_strcmp(*av, "julia") == 0)
        julia(fractol);
    controler(fractol);
    mlx_loop(fractol->mlx);
    return 0;
}