/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface_julia.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:13:42 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/20 21:10:46 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	user_interface_julia(void)
{
	ft_putstr("╔══════════════════════════════════════════╗\n");
	ft_putstr("║      Usage: ./fractol julia <x> <y>      ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	ft_putstr("           ╔════════════════════╗           \n");
	ft_putstr("╔══════════╣ Important Notice   ╠══════════╗\n");
	ft_putstr("║          ╚════════════════════╝          ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("║      - Inputs must be numbers only       ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	exit(0);
}
