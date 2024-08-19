/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:10 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/12 17:39:41 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_factal(t_fractal *fractal, char *str)
{
	if (ft_strncmp(str, "mandelbrot", 10) == 0)
		fractal->name = "mandelbrot";
	else if ((ft_strncmp(str, "julia", 5) == 0))
		fractal->name = "julia";
	else if (ft_strncmp(str, "tricorn", 7) == 0)
		fractal->name = "tricorn";
	else
	{
		exit_on_error(HELP);
		return ;
	}
}

void	get_julia_values(t_fractal *fractal, int ac, char **av)
{
	if (ft_strncmp(fractal->name, "julia", 5) != 0 || ac == 2)
	{
		fractal->julia_cx = -0.766667;
		fractal->julia_cy = -0.090000;
		return ;
	}
	if (ac == 3)
		exit_on_error(HELP);
	fractal->julia_cx = ft_atof(av[2]);
	fractal->julia_cy = ft_atof(av[3]);
	if (fractal->julia_cx > 2.0 || fractal->julia_cx < -2.0)
		exit_on_error(HELP);
	if (fractal->julia_cy > 2.0 || fractal->julia_cy < -2.0)
		exit_on_error(HELP);
}

void	input_check(t_fractal *fractal, int ac, char **av)
{
	get_factal(fractal, av[1]);
	if ((ft_strncmp(fractal->name, "mandelbrot", 10) == 0) && ac > 2)
		exit_on_error(HELP);
	else if ((ft_strncmp(fractal->name, "tricorn", 10) == 0) && ac > 2)
		exit_on_error(HELP);
	else if ((ft_strncmp(fractal->name, "julia", 6) != 0) && ac > 3)
		exit_on_error(HELP);
	else if (ft_strncmp(fractal->name, "julia", 6) == 0 && ac > 5)
		exit_on_error(HELP);
	get_julia_values(fractal, ac, av);
}
