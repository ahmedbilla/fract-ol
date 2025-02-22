/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:35:51 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/07 18:03:04 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	close_window(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fract->mlx, fract->img);
		mlx_destroy_window(fract->mlx, fract->mlx_window);
		write(1, "\033[1;33mWindow closed!\n\033[0m", 24);
		exit(0);
	}
	return (0);
}

int	close_cross(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx, fract->img);
	mlx_destroy_window(fract->mlx, fract->mlx_window);
	write(1, "\033[1;33mWindow closed!\n\033[0m", 24);
	exit(0);
}
