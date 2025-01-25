/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:44:11 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/25 23:56:37 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct fractol
{
    void *mlx;
    void *mlx_window;
    int widht;
    int height;
} t_fractol;

int create_window(t_fractol *fractol);
void	ft_putstr(char *str);
void	user_interface(void);
int ft_strcmp(char *s1, char *s2);
int close_window(int keycode);
int close_cross(t_fractol *fract);

#endif