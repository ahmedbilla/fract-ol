/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:42:45 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/25 23:44:42 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main(int ac, char *av[])
{
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0 || ft_strcmp(av[1], "julia") == 0))
	{
			t_fractol fractol;
			if (create_window(&fractol) == 1)
				return write(2, "\033[31mWindow creation failed!\033[0m\n", 39), 1;
	}
	else
		return user_interface(), 1;
}