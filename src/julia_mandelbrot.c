/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:07:10 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:47:10 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		while (x < LENGTH)
		{
			mandelbrot_util(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}

void	julia(t_fractal *fractal)
{
	int				x;
	int				y;
	t_complex_julia	a;

	y = 0;
	a.real = fractal->jul_real;
	a.imaginary = fractal->jul_imaginary;
	mlx_clear_window(fractal->mlx, fractal->window);
	while (y < LENGTH)
	{
		x = 0;
		while (x < LENGTH)
		{
			julia_util(fractal, x, y, a);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}
