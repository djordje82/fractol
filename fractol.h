/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:01:50 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/13 14:39:50 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH	800
# define HEIGHT	800
# define MAX_ITER 60
# define MOVE_STEP 0.1
# define ZOOM_STEP 1.1

/*STRUCTS*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		color;
	double	julia_cx;
	double	julia_cy;
}	t_fractal;

/*INPUT AND ERROR HANDLING*/
# define HELP \
		"\tInvalid input. Please use: \n\t\"mandelbrot\" \
		\n\t\"julia <value_1> <value_2>\" \
		\n\t\" or \n\t\"tricorn\"\n"

void	exit_on_error(char *exit_code);
void	get_factal(t_fractal *fractal, char *str);
void	get_julia_values(t_fractal *fractal, int ac, char **av);
void	input_check(t_fractal *fractal, int ac, char **av);

/*STRING UTILS*/
double	ft_atof(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);
void	ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*RENDER*/
int		calculate_julia(double z_real, double z_imag, double c_real,
			double c_imag);
int		calculate_mandelbrot(double real, double imag);
int		calculate_tricorn(double real, double imag);
void	fractal_init(t_fractal *fractal);
int		render_fractal(t_fractal *fractal);
void	render_julia(t_fractal *fractal, double c_real, double c_imag);
void	render_mandelbrot(t_fractal *fractal);
void	render_tricorn(t_fractal *fractal);
int		generate_color(int iter, int max_iter);

/*EVENTS*/
int		close_window(t_fractal *fractal);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	hooks_init(t_fractal *fractal);
int		key_handler(int keycode, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif