/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:44:11 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/07 15:28:35 by ahbilla          ###   ########.fr       */
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
    void    *img;
    double x_min;
    double x_max;
    double y_min;
    double y_max;
    int widht;
    int height;
    double  zoom;
    double real;
    double imag;
    char *addr;
    int line_length;
    int bits_per_pixel;
    int endian;
} t_fractol;

int create_window(t_fractol *fracto,char *av[]);
// int create_window(t_fractol *fractol, char *name);
void	ft_putstr(char *str);
void	user_interface(void);
int ft_strcmp(char *s1, char *s2);
int close_window(int keycode);
int close_cross(t_fractol *fract);
// int julia(t_fractol *fractol);
int mandelbrot(t_fractol *fractol);
int controler(t_fractol *fractol);
int zoom(int button, int x, int y, t_fractol *fractol);


#endif