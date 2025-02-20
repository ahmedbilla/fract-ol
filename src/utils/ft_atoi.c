/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:39:23 by ahbilla           #+#    #+#             */
/*   Updated: 2025/02/20 20:33:29 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"


int    check_sign(char *s, int *i)
{
    int    sign;

    sign = 1;
    while (s[*i] == '-' || s[*i] == '+')
    {
        if (s[*i] == '-')
            sign = -1;
        (*i)++;
    }
    return (sign);
}
double    ft_atoi(char *s, double divisor)
{
    int        i;
    int        sign;
    double    res;
    double    fraction;

    res = 0.0;
    fraction = 0.0;
    i = 0;
     while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
        i++;
    sign = check_sign(s, &i);
    while (s[i] && (s[i] >= '0' && s[i] <= '9'))
        res = res * 10 + (s[i++] - '0');
    if (s[i] == '.')
    {
        i++;
        while (s[i] && (s[i] >= '0' && s[i] <= '9'))
        {
            fraction = fraction * 10.0 + (s[i++] - '0');
            divisor *= 10.0;
        }
        res += fraction / divisor;
    }
    return (res * sign);
}