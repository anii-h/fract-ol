/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:48:59 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:30 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(int x, int y, t_fractal *fractal, int color)
{
	char	*s;

	s = fractal->address + (y * fractal->bites_per_line
			+ x * (fractal->bites_per_pixel / 8));
	*(unsigned int *)s = color;
}

int	calculate_color(int iter_count, int set)
{
	int		r;
	int		g;
	int		b;
	double	i;

	if (iter_count == 100)
		return (0x000000);
	i = iter_count / 100.0;
	if (set == 1)
	{
		g = (int)(255 * i);
		r = (int)(100 * (1 - i));
		b = (int)(150 * i);
		return ((g) | (b << 8) | (r << 16));
	}
	else
	{
		b = (int)(255 * i);
		g = (int)(100 * (1 - i));
		r = (int)(150 * i);
		return ((b << 16) | (g << 8) | (r));
	}
}

void	julia_util(t_fractal *fractal, int x, int y, t_complex_julia c)
{
	t_complex_julia	z;
	double			current;
	int				i;

	i = 0;
	z.real = ((x - LENGTH / 2.0) * 4.0 / LENGTH) * fractal->zoom + fractal->x;
	z.imaginary = ((y - LENGTH / 2.0) * 4.0 / LENGTH)
		* fractal->zoom + fractal->y;
	while (z.real * z.real + z.imaginary * z.imaginary <= 4 && i < 100)
	{
		current = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
		z.real = current;
		i++;
	}
	put_pixel(x, y, fractal, calculate_color(i, fractal->colors));
}

void	mandelbrot_util(t_fractal *fractal, int x, int y)
{
	t_complex_julia	a;
	t_complex_julia	b;
	double			current;
	int				i;

	i = 0;
	b.real = 0;
	b.imaginary = 0;
	a.real = ((x - LENGTH / 2.0) * 4.0 / LENGTH) * fractal->zoom + fractal->x;
	a.imaginary = ((y - LENGTH / 2.0) * 4.0 / LENGTH)
		* fractal->zoom + fractal->y;
	while ((b.real * b.real + a.imaginary * a.imaginary <= 4.0) && (i < 100))
	{
		current = b.real * b.real - b.imaginary * b.imaginary + a.real;
		b.imaginary = 2.0 * b.real * b.imaginary + a.imaginary;
		b.real = current;
		i++;
	}
	put_pixel(x, y, fractal, calculate_color(i, fractal->colors));
}
