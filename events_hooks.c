/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:59:25 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/13 14:44:46 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.mlx_img);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}

void	hooks_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->win_ptr, 17, 0, close_window, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		exit(1);
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			"Fract-ol");
	if (fractal->win_ptr == NULL)
	{
		free(fractal->win_ptr);
		exit(1);
	}
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color = 0x800080;
	fractal->img.mlx_img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->img.addr = mlx_get_data_addr(fractal->img.mlx_img,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	real;
	double	imag;

	real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom) + fractal->shift_x;
	imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom)
		+ fractal->shift_y;
	if (button == Button4)
	{
		fractal->zoom *= 1.05;
		fractal->shift_x = real - (x - WIDTH / 2.0) * 4.0 / (WIDTH
				* fractal->zoom);
		fractal->shift_y = imag - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT
				* fractal->zoom);
	}
	else if (button == Button5)
	{
		fractal->zoom *= 0.95;
		fractal->shift_x = real - (x - WIDTH / 2.0) * 4.0 / (WIDTH
				* fractal->zoom);
		fractal->shift_y = imag - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT
				* fractal->zoom);
	}
	return (0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_window(fractal);
	if (keycode == XK_Left)
		fractal->shift_x -= MOVE_STEP / fractal->zoom;
	else if (keycode == XK_Right)
		fractal->shift_x += MOVE_STEP / fractal->zoom;
	else if (keycode == XK_Up)
		fractal->shift_y -= MOVE_STEP / fractal->zoom;
	else if (keycode == XK_Down)
		fractal->shift_y += MOVE_STEP / fractal->zoom;
	else if (keycode == XK_plus)
		fractal->zoom *= ZOOM_STEP;
	else if (keycode == XK_minus)
		fractal->zoom /= ZOOM_STEP;
	if (keycode == XK_1 || keycode == XK_2 || keycode == XK_3)
	{
		render_fractal(fractal);
	}
	return (0);
}
