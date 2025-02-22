/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:58:27 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/08 22:33:42 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	user_interface(void)
{
	ft_putstr("╔══════════════════════════════════════════╗\n");
	ft_putstr("║       Usage: ./fractol <fractal>         ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	ft_putstr("           ╔════════════════════╗           \n");
	ft_putstr("╔══════════╣ Available fractals ╠══════════╗\n");
	ft_putstr("║          ╚════════════════════╝          ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("║                mandelbrot                ║\n");
	ft_putstr("║                julia x y                 ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	exit(0);
}
