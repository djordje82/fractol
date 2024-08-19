/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:09:41 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/12 16:44:18 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
	{
		exit_on_error(HELP);
		return (0);
	}
	input_check(&fractal, ac, av);
	fractal_init(&fractal);
	hooks_init(&fractal);
	render_fractal(&fractal);
	mlx_loop_hook(fractal.mlx_ptr, &render_fractal, &fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
