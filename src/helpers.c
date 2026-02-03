/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:54 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:40 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	on_mouse_click(int button, int x, int y, t_fractal *fractal)
{
	double	real;
	double	imaginary;

	real = ((x - LENGTH / 2.0) * 4.0 / LENGTH) * fractal->zoom + fractal->x;
	imaginary = ((y - LENGTH / 2.0) * 4.0 / LENGTH)
		* fractal->zoom + fractal->y;
	if (button == 4)
		fractal->zoom *= 0.9;
	else if (button == 5)
		fractal->zoom *= 1.1;
	fractal->x = real - ((x - LENGTH / 2.0) * 4.0 / LENGTH) * fractal->zoom;
	fractal->y = imaginary - ((y - LENGTH / 2.0) * 4.0 / LENGTH)
		* fractal->zoom;
	if (fractal->type)
		julia(fractal);
	else
		mandelbrot(fractal);
	return (0);
}

int	on_key_press(int code, t_fractal *fractal)
{
	if (code == 65307)
		exit_program(fractal);
	else if (code == 65361)
		fractal->x += 0.1 * fractal->zoom;
	else if (code == 65362)
		fractal->y += 0.1 * fractal->zoom;
	else if (code == 65363)
		fractal->x -= 0.1 * fractal->zoom;
	else if (code == 65364)
		fractal->y -= 0.1 * fractal->zoom;
	else if (code == 99)
		fractal->colors = (fractal->colors + 1) % 3;
	if (fractal->type)
		julia(fractal);
	else
		mandelbrot(fractal);
	return (0);
}

int	exit_program(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
		mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	exit_programm(t_fractal *fractal)
{
	exit_program(fractal);
	return (0);
}
