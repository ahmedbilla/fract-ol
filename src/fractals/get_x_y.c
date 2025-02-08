/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:18:53 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/08 16:21:03 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

double get_x(double j, t_fractol *fractol)
{
    return (fractol->x_min + (j / 800.00) * (fractol->x_max - fractol->x_min));
}

double get_y(double i, t_fractol *fractol)
{
    return (fractol->y_max - (i / 800.00) * (fractol->y_max - fractol->y_min));
}