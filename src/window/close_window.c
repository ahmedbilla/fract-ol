/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:35:51 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/25 23:59:03 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int close_window(int keycode)
{
    if (keycode == 53)
    {
        // ft_putstr("Window closed!\n");
        write(1, "\033[1;33mWindow closed!\n\033[0m", 24);
        exit(0);
    }
    return 0;
}

int close_cross(t_fractol *fract)
{

    mlx_destroy_window(fract->mlx, fract->mlx_window);
    // ft_putstr("Window closed!\n");
    write(1, "\033[1;33mWindow closed!\n\033[0m", 24);
    exit(1);
}