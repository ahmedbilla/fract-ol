/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:14:02 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/31 23:01:01 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

#define ZOOM_IN 4
#define ZOOM_OUT 5

int zoom(int button, int x, int y, void *param)
{
    t_fractol *data = (t_fractol *)param;
    (void)x;
    (void)y;

    if (button == ZOOM_IN)
        data->zoom *= 0.9;
    else if (button == ZOOM_OUT)
        data->zoom *= 1.1;
    return (0);
}
int controler(t_fractol *fractol)
{

    fractol->zoom = 1.0;
    mlx_mouse_hook(fractol->mlx_window,zoom, fractol);
    // mlx_hook(fractol->mlx_window, 4, 0, zoom, fractol);
    // mlx_hook(fractol->mlx_window, 5, 0, zoom, fractol);
    return 1;
}