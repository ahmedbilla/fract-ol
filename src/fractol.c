/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:42:45 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/22 23:12:07 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_handle(char *s)
{
	int	i;
	int	dot_count;

	dot_count = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '.')
			return (1);
		if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_fractol	fractol;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		|| (ac == 4 && ft_strcmp(av[1], "julia") == 0))
	{
		fractol.x_min = -2.0;
		fractol.x_max = 2.0;
		fractol.y_min = 2.0;
		fractol.y_max = -2.0;
		if ((ac == 4 && ft_strcmp(av[1], "julia") == 0))
		{
			if (ft_handle(av[2]) || ft_handle(av[3]))
				return (user_interface_julia(), 1);
			fractol.first = ft_atoi(av[2], 1.0);
			fractol.second = ft_atoi(av[3], 1.0);
		}
		fractol.name = av[1];
		if (create_window(&fractol, &av[1]) == 1)
			return (write(2, "\033[31mWindow failed!\033[0m\n", 39), 1);
	}
	else
		return (user_interface(), 1);
}
