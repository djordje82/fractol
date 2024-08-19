/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:07:32 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/13 12:48:16 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_mandelbrot(t_fractal *fractal)
{
	int		iter;
	double	real;
	double	imag;
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom)
				+ fractal->shift_x;
			imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom)
				+ fractal->shift_y;
			iter = calculate_mandelbrot(real, imag);
			fractal->color = generate_color(iter, MAX_ITER);
			ft_pixel_put(&fractal->img, x, y, fractal->color);
			x++;
		}
		y++;
	}
}

void	render_julia(t_fractal *fractal, double c_real, double c_imag)
{
	int		iter;
	double	real;
	double	imag;
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom)
				+ fractal->shift_x;
			imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom)
				+ fractal->shift_y;
			iter = calculate_julia(real, imag, c_real, c_imag);
			fractal->color = generate_color(iter, MAX_ITER);
			ft_pixel_put(&fractal->img, x, y, fractal->color);
			x++;
		}
		y++;
	}
}

void	render_tricorn(t_fractal *fractal)
{
	int		iter;
	double	real;
	double	imag;
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom)
				+ fractal->shift_x;
			imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom)
				+ fractal->shift_y;
			iter = calculate_tricorn(real, imag);
			fractal->color = generate_color(iter, MAX_ITER);
			ft_pixel_put(&fractal->img, x, y, fractal->color);
			x++;
		}
		y++;
	}
}

int	render_fractal(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
		render_julia(fractal, fractal->julia_cx, fractal->julia_cy);
	else if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		render_mandelbrot(fractal);
	else if (ft_strncmp(fractal->name, "tricorn", 10) == 0)
		render_tricorn(fractal);
	else
	{
		exit_on_error(HELP);
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.mlx_img, 0, 0);
	return (0);
}
