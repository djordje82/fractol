/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:08:14 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/13 14:39:19 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	z_real_squared;
	double	z_imag_squared;
	int		i;

	z_real = 0;
	z_imag = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		z_real_squared = z_real * z_real;
		z_imag_squared = z_imag * z_imag;
		if (z_real_squared + z_imag_squared > 4.0)
			return (i);
		z_imag = 2 * z_real * z_imag + imag;
		z_real = z_real_squared - z_imag_squared + real;
		i++;
	}
	return (0);
}

int	calculate_julia(double z_real, double z_imag, double c_real, double c_imag)
{
	double	z_real_squared;
	double	z_imag_squared;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		z_real_squared = z_real * z_real;
		z_imag_squared = z_imag * z_imag;
		if (z_real_squared + z_imag_squared > 4.0)
			return (i);
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = z_real_squared - z_imag_squared + c_real;
		i++;
	}
	return (0);
}

int	calculate_tricorn(double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (i < MAX_ITER)
	{
		if (z_real * z_real + z_imag * z_imag > 4.0)
			return (i);
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = -2 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (0);
}

int	generate_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
